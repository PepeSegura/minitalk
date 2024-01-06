/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:25:48 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/24 12:51:21 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns the length of a string
 * 
 * @param str The string to be measured.
 * 
 * @return The length of the string.
 */
int	ft_strlen_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * Ft_putchar() writes a single character to the standard output
 * 
 * @param c the character to print
 * 
 * @return The number of bytes written.
 */
int	ft_putchar_printf(int fd, int c)
{
	return (write(fd, &c, 1));
}

/**
 * Ft_putstr() writes a string to the standard output
 * 
 * @param str the string to print
 * 
 * @return The length of the string.
 */
int	ft_putstr_printf(int fd, char *str)
{
	if (!str)
		str = "(null)";
	return (write(fd, str, ft_strlen(str)));
}
