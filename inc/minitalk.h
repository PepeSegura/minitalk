/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/16 13:49:30 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//Header files
# include "minitalk.h"
# include "libs.h"

//Libft
# include "../libft/inc/libft.h"

typedef struct s_client {
	pid_t	pid_client;
	char	*pid_client_b;
	pid_t	pid_server;
}	t_client;

typedef struct s_server {
	int				len;
	char			size_next[33];
	char			*msg;
	char			*result;
	int				int_next;
	int				index_buffer;
	char			buffer[9];
	unsigned char	letter;	
}	t_server;

//Constantes
# define USAGE "Usage:\n\t./client [pid_server] [message]\n"

/* client.c */


/* server.c */

/* utils.c */
char	*decimalToBinary(int num);
int		binaryToInt(char *binary);

/* errors.c */


#endif
