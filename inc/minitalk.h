/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:49:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/08 14:19:14 by psegura-         ###   ########.fr       */
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
int		binaryToInt(char *binary);

/* errors.c */


#endif
