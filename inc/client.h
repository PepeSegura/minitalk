/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:19:04 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/26 20:21:35 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "shared.h"

# define USAGE "\rUsage:\n\t./client [pid_server] [message]"
# define BAD_SIGNAL "Signal sending failed: Operation not permitted."

void	append_char_bits_to_string(unsigned char c, char *string, int *index);
char	*str_to_binary(char *str);

int	ping(int pid);
// void	send_signals(int pid_server, char *str);
char	*binary_to_str(char *binary_string);

char	*int_to_binary(int num, int size);

void	ft_print_error(char *error_msg);

#endif
