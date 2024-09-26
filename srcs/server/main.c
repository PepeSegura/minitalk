/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:49 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/26 21:20:23 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_global	g_client;

static int	lost_signal(int s_si_pid, int signum, void *context)
{
	(void)context;
	if (s_si_pid == 0 && (signum == SIGUSR1 || signum == SIGUSR2))
	{
		ft_printf("client: %d with signal: %d\n", s_si_pid, signum);
		s_si_pid = g_client.actual_pid;
	}
	return (s_si_pid);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	info->si_pid = lost_signal(info->si_pid, signum, context);
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
		handle_header(signum);
	else if (g_client.getting_msg == 1)
		handle_msg(signum);
	if (g_client.client_pid != 0 && (signum == SIGUSR1 || signum == SIGUSR2))
		kill(g_client.client_pid, SIGNAL_RECEIVED);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			sigset;
	pid_t				server_pid;

	ft_memset(&g_client, 0, sizeof(t_global));
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sa.sa_mask = sigset;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	keep_server_up();
	return (0);
}
