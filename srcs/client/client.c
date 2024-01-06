/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:24:07 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/06 19:14:40 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <sys/time.h>

typedef struct s_client
{
	pid_t	client_pid;
	pid_t	server_pid;
	char	*msg;
}	t_client;

t_client				data;

void	init_data(int argc, char **argv)
{
	if (argc != 3)
		ft_print_error(USAGE);
	ft_memset(&data, 0, sizeof(t_client));
	data.server_pid = ft_atoi(argv[1]);
	data.client_pid = getpid();
	dprintf(2, "PID CLIENT %d\n", data.client_pid);
	data.msg = argv[2];
	if (data.server_pid == 0)
		ft_print_error(BAD_SIGNAL);
}

void	send_bit(pid_t pid, int signal)
{
	if (kill(pid, signal))
		ft_print_error("Signal sending failed.");
}

volatile sig_atomic_t	server_ready = 0;

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum, (void)context, (void)info;
	if (signum == SIGUSR1)
	{
		server_ready = 1;
	}
}

void	send_signals(char *str)
{
	int					i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			send_bit(data.server_pid, SIGUSR1);
		if (str[i] == '1')
			send_bit(data.server_pid, SIGUSR2);
		i++;
		while (!server_ready)
			pause();
		server_ready = 0;
	}
}

char	*create_header(char *msg)
{
	int		len;
	char	*header;

	len = ft_strlen(msg);
	header = nbr_to_header(len, 32);
	return (header);
}

int	main(int argc, char **argv)
{
	char				*msg_binary;
	char				*header;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);

	init_data(argc, argv);
	msg_binary = conver_str_to_bits(data.msg);
	header = create_header(msg_binary);
	send_signals(header);
	send_signals(msg_binary);
	printf("Sent %d SIGUSR1 signals to the server (PID %d)\n", ft_strlen(data.msg) * 8, data.server_pid);
	return (0);
}
