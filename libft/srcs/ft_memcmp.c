/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:28:42 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:55:07 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It compares the first n bytes of the memory areas s1 and s2
 * 
 * @param s1 This is the first string to be compared.
 * @param s2 The string to be compared.
 * @param n The number of bytes to compare.
 * 
 * @return The difference between the first two different characters. 
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_aux;
	unsigned char	*s2_aux;

	i = 0;
	s1_aux = (unsigned char *)s1;
	s2_aux = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_aux[i] == s2_aux[i])
			i++;
		else if (s1_aux[i] != s2_aux[i])
			return (s1_aux[i] - s2_aux[i]);
	}
	return (0);
}
