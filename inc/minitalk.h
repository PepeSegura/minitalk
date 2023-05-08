/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/08 12:23:48 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//Header files
# include "minitalk.h"
# include "libs.h"

//Libft
# include "../libft/inc/libft.h"

typedef struct s_cosas {
	int				len;
	char			size_next[33];
	char			buffer[9];
	unsigned char	letter;	
}	t_cosas;


//Constantes
# define USAGE "Usage:\n\t./client [server_pid] [message]\n"

/* client.c */


/* server.c */

/* utils.c */
char	*decimalToBinary(int num);
int		
(char *binary);

/* errors.c */


#endif
