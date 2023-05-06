/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:56:56 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:56:21 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It copies the string s1 into a new string, but without the characters
 * in set at the beginning and end of s1
 * 
 * @param s1 The string to be trimmed.
 * @param set The characters to be trimmed from the string.
 * 
 * @return A pointer to a new string. 
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final;
	size_t	i;
	size_t	size;

	final = NULL;
	if (s1 != NULL && set != NULL)
	{
		i = 0;
		size = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[size -1] && ft_strrchr(set, s1[size -1]) && size > i)
			size--;
		final = malloc(sizeof(char) * (size - i + 1));
		if (final == NULL)
			return (NULL);
		ft_strlcpy(final, &s1[i], size - i + 1);
	}
	return (final);
}
