/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:04 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/10 14:04:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "shared.h"

# define USAGE "\rUsage:\n\t./client [pid_server] [message]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

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
void	signal_handler(int signum, siginfo_t *info, void *context);
void	send_signals(char *str, t_info *data);
char	*create_header(char *msg);

#endif
