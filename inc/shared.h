/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:02:59 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/26 17:46:08 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "../libft/inc/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	print_bytes(char *str);

char	*str_to_binary(char *str);
char	*int_to_binary(int nbr, int size);

char	*binary_to_str(char *binary);
int		binary_to_int(char *binary);

void	ft_print_error(char *error_msg);

#endif
