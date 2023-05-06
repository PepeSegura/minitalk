/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:22:30 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 21:14:14 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function returns the length of the number.
 * 
 * @param n the number to be converted
 * 
 * @return The length of the number. 
 */
static int	ft_len(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/**
 * It takes a number, converts it to a string, and returns a pointer to that
 * string
 * 
 * @param c the string that will be returned
 * @param digit the number to be converted to a string
 * @param len the length of the string
 * 
 * @return The address of the first element of the array.
 */
static void	*ft_savenbr(char *c, size_t digit, int len)
{
	while (digit > 0)
	{
		c[len - 1] = (digit % 10) + '0';
		digit = digit / 10;
		len--;
	}
	return (c);
}

/**
 * It takes an integer and returns a string representation of that integer
 * 
 * @param n the number to be converted to a string
 * 
 * @return A string of the number.
 */
char	*ft_itoa(int n)
{
	char		*dst;
	int			len;
	long long	n_long;

	n_long = (long long)n;
	len = ft_len(n_long);
	dst = malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	dst[len] = '\0';
	if (n_long == 0)
		dst[0] = '0';
	if (n_long < 0)
	{
		n_long = n_long * -1;
		dst[0] = '-';
	}
	dst = ft_savenbr(dst, n_long, len);
	return (dst);
}
