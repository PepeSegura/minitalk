/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:57:43 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:55:14 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_memset() takes a pointer to a memory area, a byte value, and a size, and
 * fills the memory area with the given byte value
 * 
 * @param b This is the pointer to the memory area to be filled.
 * @param c the character to fill the memory with
 * @param len the number of bytes to fill
 * 
 * @return The address of the first byte of the memory area b. 
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*tmp;

	tmp = b;
	i = 0;
	while (i < len)
		tmp[i++] = (unsigned char)c;
	return (b);
}
