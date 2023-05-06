/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:21:19 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:55:17 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Write the character c to the file descriptor fd
 * 
 * @param c the character to print
 * @param fd file descriptor 
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
