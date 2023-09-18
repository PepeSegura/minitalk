/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:24:07 by psegura-          #+#    #+#             */
/*   Updated: 2023/09/18 20:33:03 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	pid_t			client_pid;
	int				signal_ammount = atoi(argv[1]);

	pid_t server_pid;

	client_pid = getpid();
	printf("Client PID: %d\n", client_pid);
	printf("Enter the server's PID: ");
	scanf("%d", &server_pid);

	for (int i = 0; i < signal_ammount; i++)
	{
		if (kill(server_pid, SIGUSR1))
		{
			perror("Signal sending failed");
			exit(EXIT_FAILURE);
		}
		usleep(150);
	}
	printf("Sent %d SIGUSR1 signals to the server (PID %d)\n", signal_ammount, server_pid);
	return (0);
}
