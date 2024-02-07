/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:23:44 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/07 21:41:37 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "shared.h"

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
	int						client_pid;
	int						actual_pid;
	volatile sig_atomic_t	is_ready;
	t_msg					msg;
}	t_global;

extern t_global	g_client;

int		pong(int pid);

char	set_input(int signum);
void	store_signals_for_header(int *i, char input);
void	memory_reserve_to_store_signals(int *i);
void	store_signals(int *i, char input);
void	create_and_print_final_message(int *i);

#endif
