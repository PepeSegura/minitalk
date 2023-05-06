/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:12:17 by psegura-          #+#    #+#             */
/*   Updated: 2022/10/30 23:06:00 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_bzero() takes a pointer to a memory area and a size_t value as parameters,
 * and sets the memory area to zero
 * 
 * @param s This is the pointer to the memory area to be filled.
 * @param n The number of bytes to be set to zero. 
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
		tmp[i++] = 0;
}
