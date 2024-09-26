/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:04 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/26 19:09:48 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "shared.h"

# define USAGE "\rUsage:\n\t./client [pid_server] [message]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

# define CHAR_0 SIGUSR1
# define CHAR_1 SIGUSR2

typedef struct s_client
{
	pid_t	client_pid;
	pid_t	server_pid;
	char	*msg;
}	t_client;

typedef struct s_global
{
	int						pid;
	volatile sig_atomic_t	is_ready;
}	t_global;

extern t_global	g_server;

void	parser(int argc, char **argv);
int		ping(int pid);

void	init_data(char **argv, t_client *data);
void	send_signal(pid_t pid, int signal);
void	send_signals(void *data, size_t bit_length, t_client *info);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	send_message(char *str, t_client *data);

#endif
