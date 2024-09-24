/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:49 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/24 19:55:36 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

# define TIMEOUT 5
# define SLEEP_TIME 500000

t_global	g_client;

int	check_clean_status(void)
{
	volatile sig_atomic_t has_client = 0;
	int i = 0;

	if (g_client.actual_pid == 0)
	{
		has_client = 0;
		sleep (1);
		return (1);
	}
	has_client = 1;
	while (has_client && i < TIMEOUT)
	{
		usleep(SLEEP_TIME);
		if (g_client.client_activity)
        {
			g_client.client_activity = 0;
            i = 0;
        }
		i++;
	}
	if (i == TIMEOUT)
	{
		g_client.client_activity = 0;
		if (g_client.msg.message != NULL)
		{
			write(2, "There was a problem with the last client\n", 42);
			free(g_client.msg.message);
			ft_bzero(&g_client, sizeof(g_client));
			g_client.getting_header = 1;
		}
	}
	return (0);
}

void	keep_server_up(void)
{
	while (1)
	{
		check_clean_status();
	}
}

static int	lost_signal(int s_si_pid, int signum, int *i, void *context)
{
	(void)context;
	if (s_si_pid == 0 && (signum == SIGUSR1 || signum == SIGUSR2))
	{
		ft_printf("i: [%d] client: %d with signal: %d\n", (*i), s_si_pid,
			signum);
		s_si_pid = g_client.actual_pid;
	}
	return (s_si_pid);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
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
	g_client.client_activity = 1;
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
	// sigset_t			sigset;
	pid_t				server_pid;

	ft_memset(&g_client, 0, sizeof(t_global));
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	// sigemptyset(&sigset);
	// sigaddset(&sigset, SIGUSR1);
	// sigaddset(&sigset, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	// sa.sa_mask = sigset;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	keep_server_up();
	return (0);
}
