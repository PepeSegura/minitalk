/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:24:07 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/10 14:04:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_data(char **argv, t_info *data)
{
	ft_memset(data, 0, sizeof(t_info));
	data->server_pid = ft_atoi_limits(argv[1]);
	data->client_pid = getpid();
	ft_dprintf(2, "PID CLIENT %d\n", data->client_pid);
	data->msg = argv[2];
	if (data->server_pid == 0)
		ft_print_error(BAD_SIGNAL);
}

void	send_signal(pid_t pid, int signal)
{
	if (kill(pid, signal))
		ft_print_error("Signal sending failed.");
	g_server.is_ready = 0;
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum, (void)context, (void)info;
	if (signum == SIGUSR2)
	{
		g_server.is_ready = 1;
		g_server.sig_count++;
	}
}

void	send_signals(char *str, t_info *data)
{
	struct sigaction	sa;
	int					i;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			send_signal(data->server_pid, SIGUSR1);
		if (str[i] == '1')
			send_signal(data->server_pid, SIGUSR2);
		i++;
		sleep(1);
	}
}

char	*create_header(char *msg)
{
	int		len;
	char	*header;

	len = ft_strlen(msg);
	header = int_to_binary(len, 32);
	return (header);
}
