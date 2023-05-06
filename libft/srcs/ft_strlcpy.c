/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:17:55 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:55:51 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy the string pointed to by src, including the terminating null byte ('\0'),
 * to the buffer pointed to by dest. The strings may not overlap, and the
 * destination string dest must be large enough to receive the copy. Beware of
 * buffer overruns! (See BUGS.) 
 * 
 * @param dest This is the destination string.
 * @param src The string to be copied.
 * @param size The maximum number of bytes to be copied from src.
 * 
 * @return The length of the string src.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
