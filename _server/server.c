/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:23:17 by psegura-          #+#    #+#             */
/*   Updated: 2023/09/20 18:47:17 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_clients	*client_list = NULL;
int			clients = 0;

void	print_clients(void)
{
	t_clients	*current;

	current = client_list;
	printf("Clients and their 'i' values:\n");
	while (current != NULL)
	{
		printf("Client PID: %d, 'i' value: %d\n", current->pid, current->i);
		current = current->next;
	}
}

int	add_client(pid_t client_pid)
{
	t_clients	*current;
	t_clients	*new_client;

	// Check if the client is already in the list
	current = client_list;
	while (current != NULL)
	{
		if (current->pid == client_pid)
		{
			//Add content to the buffer, and if buffer is filled, convert to letter and print
			current->i++;
			if (current->i == 31)
				printf("GOT HEADER!!! for client [%d]\n", current->pid);
			return (0);
		}
		current = current->next;
	}
	// Create a new client node
	new_client = malloc(sizeof(t_clients));
	if (new_client == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	new_client->pid = client_pid;
	new_client->i = 0; // Initialize other fields as needed
	new_client->next = client_list;
	// Update the list head
	client_list = new_client;
	printf("Added new client (PID %d) to the list\n", client_pid);
	return (1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum, (void)context;
	pid_t		client_pid;
	
	client_pid = info->si_pid;
	clients += add_client(client_pid);
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	printf("Number of clients: %d\n", clients);
	if (clients == 3)
		print_clients();
	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server is waiting for a signal...\n");
	while (1)
	{
		pause();
		if (clients == 3)
			print_clients();
	}
	return (0);
}
