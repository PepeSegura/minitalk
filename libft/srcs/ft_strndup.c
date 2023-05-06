/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:23:36 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/31 21:54:34 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int len)
{
	char	*final;
	int		i;

	i = 0;
	final = malloc(sizeof(char) * len + 1);
	if (!final)
		return (NULL);
	while (s1[i] && i < len)
	{
		final[i] = s1[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
