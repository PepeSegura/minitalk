/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:23:44 by psegura-          #+#    #+#             */
/*   Updated: 2024/08/16 23:59:35 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

#include "shared.h"

# define HEADER_SIZE 32
# define SIGNAL_RECEIVED SIGUSR2

typedef struct s_msg
{
	char	header[HEADER_SIZE + 1];
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

#endif
