/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:38:57 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/14 22:45:30 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the destination is less than the source, copy the source to the 
 * destination, otherwise copy the source to the destination in reverse
 * 
 * @param dst This is the pointer to the destination array where the content is
 * to be copied, type-casted to a void*.
 * @param src The source string.
 * @param len the number of bytes to copy
 * 
 * @return A pointer to the destination string. 
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	char			*lastd;
	const char		*lasts;

	d = dst;
	s = src;
	lasts = s + (len - 1);
	lastd = d + (len - 1);
	if (dst == NULL && src == NULL)
		return (NULL);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}
