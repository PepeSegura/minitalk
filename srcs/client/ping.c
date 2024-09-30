/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:05:47 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/30 15:04:31 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

#define RETRY_TIMES 10
#define RETRY_TIME 1
#define RETRY_INTERVALS 20

#define SERVER_READY SIGUSR1
#define SERVER_BUSY SIGUSR2

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
		exit(1);
	}
	if (signum == SERVER_READY)
		g_server.is_ready = 1;
	if (signum == SERVER_BUSY)
		g_server.is_ready = 0;
}

int	ckeck_server_and_sleep(void)
{
	const int	total_sleep = RETRY_TIME * 1000 * 1000;
	const int	sleep_time = total_sleep / RETRY_INTERVALS;
	int			i;

	i = 0;
	while (i <= total_sleep)
	{
		usleep(sleep_time);
		if (g_server.is_ready == 1)
			return (1);
		i += sleep_time;
	}
	return (0);
}

int	handle_timeouts(int pid)
{
	int	i;

	i = 0;
	while (++i <= RETRY_TIMES)
	{
		kill(pid, SIGUSR1);
		write(1, "Waiting response from server\n", 30);
		if (ckeck_server_and_sleep())
			return (0);
	}
	return (1);
}

int	ping(int pid)
{
	struct sigaction	sa;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ping_handler;
	sa.sa_mask = sigset;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_server.pid = pid;
	g_server.is_ready = 0;
	if (handle_timeouts(pid))
		ft_print_error("Coudn't reach server pid.");
	ft_printf("Server ready, sending msg.\n");
	return (g_server.is_ready);
}
