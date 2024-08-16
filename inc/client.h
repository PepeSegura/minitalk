/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:04 by psegura-          #+#    #+#             */
/*   Updated: 2024/08/16 23:59:40 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include "shared.h"

# define USAGE "\rUsage:\n\t./client [pid_server] [message]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

# define CHAR_0 SIGUSR1
# define CHAR_1 SIGUSR2

typedef struct s_data
{
	pid_t	client_pid;
	pid_t	server_pid;
	char	*msg;
}	t_info;

typedef struct s_global
{
	int						sig_count;
	int						pid;
	volatile sig_atomic_t	is_ready;
}	t_global;

extern t_global	g_server;

void	parser(int argc, char **argv);
int		ping(int pid);

void	init_data(char **argv, t_info *data);
void	send_signal(pid_t pid, int signal);
void	send_signals(void *data, size_t bit_length, t_info *info);
void	signal_handler(int signum, siginfo_t *info, void *context);
void	send_message(char *str, t_info *data);

#endif
