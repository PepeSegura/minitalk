/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:16:38 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/30 23:00:24 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a format character and a va_list, and returns the number of
 * characters printed
 * 
 * @param args the va_list that contains all the arguments passed
 * to the function.
 * @param format the format specifier
 * 
 * @return The number of characters printed.
 */
static int	ft_format(va_list args, char format)
{
	int	dest;

	dest = 0;
	if (format == '%')
		dest += ft_putchar_printf('%');
	else if (format == 'c')
		dest += ft_putchar_printf(va_arg(args, int));
	else if (format == 's')
		dest += ft_putstr_printf(va_arg(args, char *));
	else if (format == 'p')
		dest += ft_pointer(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		dest += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		dest += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (format == 'x')
		dest += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		dest += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else
		dest += ft_putstr_printf(va_arg(args, char *));
	return (dest);
}

/**
 * The function ft_printf() takes a string and a variable number of arguments,
 and returns the number of characters printed
 * 
 * @param string The string to be printed.
 * 
 * @return The number of characters printed.
 */
int	ft_printf(char const *string, ...)
{
	va_list	args;
	int		d_type;
	int		i;

	d_type = 0;
	i = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			d_type = d_type + ft_format(args, string[i + 1]);
			i++;
		}
		else
			d_type = d_type + write(1, &string[i], 1);
		i++;
	}
	return (d_type);
}
