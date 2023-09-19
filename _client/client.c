/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:24:07 by psegura-          #+#    #+#             */
/*   Updated: 2023/09/19 19:08:56 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

typedef struct s_client
{
	pid_t	client_pid;
	pid_t	server_pid;
	char	flag;
	char	*msg;
} t_client;

t_client	data;

void	init_data(int argc, char **argv)
{
	if (argc != 3)
		ft_print_error(USAGE);
	ft_memset(&data , 0, sizeof(t_client));
	data.server_pid = ft_atoi(argv[1]);
	data.client_pid = getpid();
	data.msg = argv[2];
	if (data.server_pid == 0)
		ft_print_error(BAD_SIGNAL);
}

void	send_bit(pid_t pid, int signal)
{
	if (kill(pid, signal))
		ft_perror("Signal sending failed");
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum, (void)context, (void)info;
	pid_t		server_pid;

	server_pid = info->si_pid;
	printf("Received SIGUSR1 signal from SERVER (PID %d)\n", server_pid);
}

void	send_signals(char *str)
{
	int	i;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO; // Use the extended signal handler with si_pid
	sa.sa_sigaction = signal_handler;

	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			send_bit(data.server_pid, SIGUSR1);
		if (str[i] == '1')
			send_bit(data.server_pid, SIGUSR2);
		i++;
		pause();
	}
}

int	main(int argc, char **argv)
{
	init_data(argc, argv);
	printf("Client PID: %d\n", data.client_pid);

	char 	*msg_binary = conver_str_to_bits(data.msg);

	send_signals(msg_binary);
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (kill(data.server_pid, SIGUSR1))
	// 		ft_perror("Signal sending failed");
	// 	usleep(150);
	// }
	printf("Sent %d SIGUSR1 signals to the server (PID %d)\n", ft_strlen(data.msg) * 8, data.server_pid);
	
	return (0);
}
