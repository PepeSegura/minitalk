/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 21:20:25 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:55:22 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Write the number n to the file descriptor fd
 * 
 * @param n The number to be printed.
 * @param fd The file descriptor of the file to write to. 
 */
void	ft_putnbr_fd(int n, int fd)
{
	long long	number;

	number = (long long)n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = number * -1;
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		number = number % 10;
	}
	ft_putchar_fd(number + '0', fd);
}
