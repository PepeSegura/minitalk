/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:24:07 by psegura-          #+#    #+#             */
/*   Updated: 2024/08/16 23:55:07 by psegura-         ###   ########.fr       */
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

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum, (void)context, (void)info;
	if (signum == SIGUSR2)
	{
		g_server.is_ready = 1;
		g_server.sig_count++;
	}
}

void	send_signal(pid_t pid, int signal)
{
	if (kill(pid, signal))
		ft_print_error("Signal sending failed.");
	g_server.is_ready = 0;
}

void	send_signals(void *data, size_t bit_length, t_info *info)
{
	unsigned long long  value;
    int                 i;

	value = 0;
	if (bit_length == 8)
		value = *((unsigned char *)data);
	else if (bit_length == 32)
		value = *((unsigned int *)data);

	i = bit_length - 1;
    while (i >= 0)
	{
		if (value & (1ULL << i))
		{
			write(1, "1", 1);
			send_signal(info->server_pid, CHAR_1);
		}
		else
		{
			write(1, "0", 1);
			send_signal(info->server_pid, CHAR_0);
		}
        i--;
		usleep(10 * 1000);
	}
	write(1, "\n", 1);
}

void	send_message(char *str, t_info *data)
{
	struct sigaction	sa;
	int					i;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	while (str[i])
	{
		send_signals(&str[i], 8, data);
		i++;
	}
}
