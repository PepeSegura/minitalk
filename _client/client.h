/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:04 by psegura-          #+#    #+#             */
/*   Updated: 2023/09/20 16:39:41 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/inc/libft.h"

# define USAGE "Usage:\n\t./client [pid_server] [message]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

void	append_char_bits_to_string(char c, char *string, int *index);
char	*conver_str_to_bits(char *str);
// void	send_signals(int pid_server, char *str);
char	*binary_to_ascii(char *binary_string);

char	*nbr_to_header(int num, int size);


void	ft_print_error(char *error_msg);
void	ft_perror(char *error_msg);

#endif
