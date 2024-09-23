/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:23:44 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/23 23:40:50 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "shared.h"

# define HEADER_SIZE 32
# define SIGNAL_RECEIVED SIGUSR2

# define HEADER_MESSAGE "\033[4mMessage:\033[0m\n"

typedef struct s_msg
{
	int		size_message;
	char	*message;
}	t_msg;

typedef struct s_global
{
	volatile sig_atomic_t		client_pid;
	volatile sig_atomic_t		actual_pid;
	volatile sig_atomic_t		getting_header;
	volatile sig_atomic_t		getting_msg;
	volatile sig_atomic_t		client_activity;
	volatile sig_atomic_t		sig_count;
	char	char_value;
	volatile sig_atomic_t		msg_pos;
	t_msg	msg;
}	t_global;

extern t_global	g_client;

int		pong(int pid);
void	handle_msg(int *i, int signum);
void	handle_header(int *i, int signum);
#endif
