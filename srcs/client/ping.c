/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:05:47 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/14 20:18:56 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#define RETRY_TIMES 30
#define RETRY_TIME 2

#define SERVER_READY SIGUSR1
#define SERVER_BUSY SIGUSR2

t_global	g_server;

void	ping_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum, (void)context, (void)info;
	if (info->si_pid == getpid())
	{
		ft_dprintf(2, "Error: Own process\n");
		exit(1);
	}
	if (info->si_pid != g_server.pid)
	{
		ft_dprintf(2, "Error: Unexpected pid in ping_handler\n");
		return ;
	}
	if (signum == SERVER_READY)
		g_server.is_ready = 1;
	if (signum == SERVER_BUSY)
		g_server.is_ready = 0;
}

void	handle_timeouts(int pid)
{
	int	i;

	i = -1;
	while (++i < RETRY_TIMES)
	{
		kill(pid, SIGUSR1);
		ft_printf("Waiting response from server\n");
		sleep(RETRY_TIME);
		if (g_server.is_ready == 1)
			break ;
	}
}

int	ping(int pid)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ping_handler;
	g_server.pid = pid;
	g_server.is_ready = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	handle_timeouts(pid);
	ft_printf("Server ready: %d\n", g_server.is_ready);
	return (g_server.is_ready);
}
