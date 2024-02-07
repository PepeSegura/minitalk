/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:49 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/07 21:40:08 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_global	g_client;

void	keep_server_up(void)
{
	while (1)
		sleep(1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;
	char		input;

	if (info->si_pid == getpid())
		ft_print_error("Own process");
	g_client.client_pid = info->si_pid;
	if (g_client.actual_pid == 0)
	{
		pong(g_client.client_pid);
		return ;
	}
	if (info->si_pid != g_client.actual_pid)
		return ;
	(void)context, (void)signum;
	input = set_input(signum);
	if (i < HEADER_SIZE)
		store_signals_for_header(&i, input);
	if (i == HEADER_SIZE)
		memory_reserve_to_store_signals(&i);
	else if (i >= HEADER_SIZE && i <= g_client.msg.size_message + HEADER_SIZE)
		store_signals(&i, input);
	if (i > g_client.msg.size_message + HEADER_SIZE)
		create_and_print_final_message(&i);
	if (signum == SIGUSR1 || signum == SIGUSR2)
		kill(g_client.client_pid, SIGNAL_RECEIVED);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	ft_memset(&g_client, 0, sizeof(t_global));
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	keep_server_up();
	return (0);
}