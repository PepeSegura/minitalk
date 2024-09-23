/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:23:44 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/23 18:40:26 by psegura-         ###   ########.fr       */
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
	int		client_pid;
	int		actual_pid;
	int		getting_header;
	int		getting_msg;
	t_msg	msg;
}	t_global;

extern t_global	g_client;

int		pong(int pid);
void	handle_msg(int *i, int signum);
void	handle_header(int *i, int signum);
#endif
