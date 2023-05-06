/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:07:00 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:55:04 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It iterates through the first n bytes of the memory area pointed to by s, and
 * returns a pointer to the first byte that matches the value of c
 * 
 * @param s The memory area to be searched.
 * @param c The character to search for.
 * @param n The number of bytes to be checked.
 * 
 * @return a pointer to the first occurrence of the character c in the first n
 * bytes of the string pointed to, by the argument s. 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux_s;
	unsigned char	aux_c;

	i = 0;
	aux_s = (unsigned char *)s;
	aux_c = (unsigned char)c;
	while (n > i)
	{
		if (aux_s[i] == aux_c)
			return ((void *)aux_s + i);
		i++;
	}
	return (0);
}
