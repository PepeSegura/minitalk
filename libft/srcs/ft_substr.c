/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:18:26 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:56:24 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It returns the minimum of two integers
 * 
 * @param a the first number
 * @param b the number of bytes to read
 * 
 * @return The minimum of two integers.
 */
static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * If the string is shorter than the start index, return an empty string,
 * otherwise return a string of length len starting at index start.
 * 
 * @param s The string to be split.
 * @param start the index of the first character to include in the substring.
 * @param len the maximum number of characters to copy
 * 
 * @return A pointer to a new string. 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if ((size_t)ft_strlen(s) < start)
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(ft_min(ft_strlen(s) - start, len) + 1);
	if (!str)
		return (0);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
