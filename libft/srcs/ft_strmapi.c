/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:36:40 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:56:09 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes a string and a function, and returns a new string where each
 * character is the result of the function applied to the corresponding
 * character of the original string
 * 
 * @param s The string to be mapped.
 * @param f The function that will be applied to each character of s.
 * 
 * @return A pointer to a new string, which is the result of applying
 * the function f to each character of the string given as argument. 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*final;
	size_t	i;

	if (!s)
		return (NULL);
	final = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (final == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		final[i] = (*f)(i, s[i]);
		i++;
	}
	final[i] = '\0';
	return (final);
}
