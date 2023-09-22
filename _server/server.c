/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:23:17 by psegura-          #+#    #+#             */
/*   Updated: 2023/09/22 22:16:54 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_clients	*client_list = NULL;
int			clients = 0;

char	*binary_to_ascii(char *binary_string)
{
	int		len;
	int		num_chunks;
	char	*ascii_string;
	char	chunk[9];
	int		ascii_val;

	len = strlen(binary_string);
	num_chunks = len / 8;
	ascii_string = (char *)malloc(num_chunks + 1);
	for (int i = 0; i < num_chunks; i++)
	{
		strncpy(chunk, binary_string + i * 8, 8);
		chunk[8] = '\0';
		ascii_val = strtol(chunk, NULL, 2);
		ascii_string[i] = (char)ascii_val;
	}
	ascii_string[num_chunks] = '\0';
	return (ascii_string);
}

double	my_pow(double x, int n)
{
	double	result;
	int		i;

	result = 1;
	i = 0;
	while (i < n)
	{
		result *= x;
		i++;
	}
	return (result);
}

int	binaryToInt(char *binary)
{
	int	result;
	int	len;
	int	i;

	result = 0;
	len = strlen(binary);
	i = 0;
	while (i < len)
	{
		if (binary[i] == '1')
		{
			result += my_pow(2, len - i - 1);
		}
		i++;
	}
	return (result);
}

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

void	add_content(t_clients	*current, char input)
{
	if (current->i < 32)
	{
		current->header[current->i] = input;
		current->i++;
	}
	if (current->i == 32)
	{
		printf("GOT HEADER!!! for client [%d]\n", current->pid);
		current->size_msg = binaryToInt(current->header);
		memset(current->header, 0, sizeof(current->header));
		current->msg_binary = malloc((current->size_msg + 1) * sizeof(char));
		if (!current->msg_binary)
			exit(1);
		current->i++;
	}
	else if (current->i >= 32 && current->i <= current->size_msg + 32)
	{
		current->msg[current->i - 33] = input;
		current->i++;
	}
	if (current->i > current->size_msg + 32)
	{
		current->msg[current->i - 33] = '\0';
		current->i = 0;
		current->result = binary_to_ascii(current->msg);
		write(1, current->result, current->size_msg / 8);
		write(1, "\n", 1);
	}
}

int	add_client(pid_t client_pid, int signal)
{
	t_clients	*current;
	t_clients	*new_client;

	char	input;

	if (signal == SIGUSR1)
		input = '1';
	if (signal == SIGUSR2)
		input = '0';
	// Check if the client is already in the list
	current = client_list;
	while (current != NULL)
	{
		if (current->pid == client_pid)
		{
			
			//Add content to the buffer, and if buffer is filled, convert to letter and print
			add_content(current, input);
			// current->i++;
			// if (current->i == 31)
			// 	printf("GOT HEADER!!! for client [%d]\n", current->pid);
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
	(void)context;
	pid_t		client_pid;
	
	client_pid = info->si_pid;
	clients += add_client(client_pid, signum);
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
