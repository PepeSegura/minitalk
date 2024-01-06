/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:23:34 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/24 12:54:50 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes an unsigned long integer and a string as arguments and
 * prints the number in the base of the string
 * 
 * @param nbr the number to be converted
 * @param b the base to convert to
 * 
 * @return The number of characters printed.
 */
int	ft_putnbr_base(int fd, unsigned long nbr, char *b)
{
	long int	number;
	static int	i;

	number = (unsigned int)nbr;
	i = 0;
	if (number >= ft_strlen_printf(b))
	{
		ft_putnbr_base(fd, number / ft_strlen_printf(b), b);
		number = number % ft_strlen_printf(b);
	}
	i++;
	ft_putchar_printf(fd, b[number]);
	return (i);
}

/**
 * It prints a hexadecimal number
 * 
 * @param nbr the number to be converted
 * 
 * @return The number of characters printed.
 */
int	ft_put_ex(int fd, size_t nbr)
{
	char		*base;
	static int	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_put_ex(fd, nbr / 16);
		nbr = nbr % 16;
	}
	i++;
	ft_putchar_printf(fd, base[nbr]);
	return (i);
}

/**
 * This function takes an integer as a parameter and prints it to the standard
 * output
 * 
 * @param nbr the number to be printed
 * 
 * @return The number of characters printed.
 */
int	ft_putnbr(int fd, int nbr)
{
	long int	number;
	static int	i;

	number = (long long)nbr;
	i = 0;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = number * -1;
	}
	if (number > 9)
	{
		ft_putnbr(fd, number / 10);
		number = number % 10;
	}
	i++;
	ft_putchar_printf(fd, number + '0');
	if (nbr < 0)
		i++;
	return (i);
}

/**
 * This function takes a pointer as an argument and prints it in
 * hexadecimal format
 * 
 * @param p the pointer to print
 * 
 * @return The length of the string.
 */
int	ft_pointer(int fd, void *p)
{
	size_t	num;
	int		len;

	len = 0;
	num = (size_t)p;
	len = write(fd, "0x", 2);
	len += ft_put_ex(fd, num);
	return (len);
}
