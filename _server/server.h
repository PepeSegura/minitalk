/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:23:44 by psegura-          #+#    #+#             */
/*   Updated: 2023/09/22 22:12:32 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/inc/libft.h"

typedef int	idx;

typedef struct s_clients
{
	pid_t	pid;
	idx		i;
	char	header[33];
	int		size_msg;
	char	*msg_binary;
	char	*msg;
	char	*result;
	char	buffer[9];
	void	*next;
}			t_clients;

#endif
