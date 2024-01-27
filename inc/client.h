/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:04 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/27 10:14:32 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "shared.h"

# define USAGE "\rUsage:\n\t./client [pid_server] [message]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

typedef struct s_global
{
	int						pid;
	volatile sig_atomic_t	is_ready;
}	t_global;

extern t_global	g_server;

void	parser(int argc, char **argv);
int		ping(int pid);

#endif
