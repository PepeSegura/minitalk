/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:23:44 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/26 17:38:02 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "shared.h"

typedef int	t_idx;

typedef struct s_clients
{
	pid_t	pid;
	t_idx	i;
	char	header[32];
	int		size_msg;
	char	*msg_binary;
	char	*msg;
	char	*result;
	char	buffer[8];
	void	*next;
}			t_clients;

void	ft_print_error(char *error_msg);

char	*binary_to_str(char *binary_string);
int		binary_to_int(char *binary);

void	keep_server_up(void);

#endif
