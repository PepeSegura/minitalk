/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:49 by psegura-          #+#    #+#             */
/*   Updated: 2024/08/18 19:37:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_global	g_client;

void	keep_server_up(void)
{
	while (1)
	{
		sleep(1);
	}
}

int	lost_signal(int s_si_pid, int signum, int *i, void *context)
{
	(void)context;
	if (s_si_pid == 0 && (signum == SIGUSR1 || signum == SIGUSR2))
	{
		ft_printf("i: [%d] client: %d with signal: %d\n", (*i), s_si_pid, signum);
		s_si_pid = g_client.actual_pid;
	}
	return (s_si_pid);
}

int	get_bit_value(int signum)
{
	if (signum == SIGUSR1)
		return (0);
	return (1);
}

void	memory_reserve_to_store_signals(int *i)
{
	printf("SIZE_MSG: [%d]\n", g_client.msg.size_message);
	g_client.msg.message = ft_calloc((g_client.msg.size_message + 1), 1);
	if (g_client.msg.message == NULL)
		ft_print_error("Malloc_failed");
	g_client.getting_header = 0;
	g_client.getting_msg = 1;
	(*i) = 0;
}

void	handle_header(int *i, int signum)
{
	const int	bit_value = get_bit_value(signum);
	
	if ((*i) < HEADER_SIZE)
	{
		g_client.msg.size_message |= (bit_value << (HEADER_SIZE - 1 - (*i)));
		(*i)++;
	}
	if ((*i) == HEADER_SIZE)
		memory_reserve_to_store_signals(i);
}

void	handle_msg(int *i, int signum)
{
	const int	bit_value = get_bit_value(signum);
	static int	char_value;
	static int	msg_pos;

    if (*i % 8 < 8)
	{
        char_value |= (bit_value << (7 - (*i % 8)));
        (*i)++;
    }
    if (*i % 8 == 0)
	{
		g_client.msg.message[msg_pos] = char_value;
        char_value = 0;
		msg_pos++;
    }
	if (*i / 8 == g_client.msg.size_message)
	{
		printf("message: [%s]\n", g_client.msg.message);
		free(g_client.msg.message);
		ft_bzero(&g_client, sizeof(g_client));
		g_client.getting_header = 1;
		(*i) = 0;
		msg_pos = 0;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	static int	i;

	info->si_pid = lost_signal(info->si_pid, signum, &i, context);
	if (info->si_pid == getpid())
		ft_print_error("Own process");
	g_client.client_pid = info->si_pid;
	if (g_client.actual_pid == 0)
	{
		pong(g_client.client_pid);
		return ;
	}
	if (g_client.actual_pid != g_client.client_pid)
		return ;
	if (g_client.getting_header == 1)
		handle_header(&i, signum);
	else if (g_client.getting_msg == 1)
		handle_msg(&i, signum);
	if (g_client.client_pid != 0 && (signum == SIGUSR1 || signum == SIGUSR2))
		kill(g_client.client_pid, SIGNAL_RECEIVED);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	ft_memset(&g_client, 0, sizeof(t_global));
	server_pid = getpid();
	ft_dprintf(1, "Server PID: %d\n", server_pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	keep_server_up();
	return (0);
}
