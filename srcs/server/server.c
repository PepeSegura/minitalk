/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:23:17 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/26 19:44:14 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/time.h>
#define HEADER_SIZE 32

t_clients	*client_list = NULL;

void	add_content(t_clients *c, char input)
{
	if (c->i < HEADER_SIZE)
	{
		c->header[c->i] = input;
		c->i++;
	}
	if (c->i == HEADER_SIZE)
	{
		c->size_msg = binary_to_int(c->header);
		memset(c->header, 0, sizeof(c->header));
		c->msg_binary = ft_calloc((c->size_msg + 1), sizeof(char));
		if (!c->msg_binary)
			ft_print_error("RIP MALLOC");
		c->i++;
	}
	else if (c->i >= HEADER_SIZE && c->i <= c->size_msg + HEADER_SIZE)
	{
		c->msg_binary[c->i - 33] = input;
		c->i++;
	}
	if (c->i > c->size_msg + HEADER_SIZE)
	{
		c->result = binary_to_str(c->msg_binary);
		write(1, c->result, c->size_msg / 8);
		write(1, "\n", 1);
	}
}

int	add_client(pid_t client_pid, int signal)
{
	t_clients	*current;
	t_clients	*new_client;
	char		input;

	if (signal == SIGUSR1)
		input = '0';
	if (signal == SIGUSR2)
		input = '1';
	current = client_list;
	while (current != NULL)
	{
		if (current->pid == client_pid)
			return (add_content(current, input), 0);
		current = current->next;
	}
	new_client = ft_calloc(1, sizeof(t_clients));
	if (new_client == NULL)
		ft_print_error("RIP MALLOC");
	new_client->pid = client_pid;
	add_content(new_client, input);
	new_client->next = client_list;
	client_list = new_client;
	printf("Added new client (PID %d) to the list\n", client_pid);
	return (1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	pid_t	client_pid;

	(void)context;
	client_pid = info->si_pid;
	add_client(client_pid, signum);
	kill(client_pid, SIGUSR1);
}

void	keep_server_up(void)
{
	while (1)
		sleep(1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				server_pid;

	server_pid = getpid();
	printf("Server PID: %d\n", server_pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	keep_server_up();
	return (0);
}
