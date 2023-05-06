/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:57:11 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/31 21:57:14 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_cosas
{
	char	*final;
	int		l_s1;
	int		l_total;
	int		i;
	int		j;
}	t_cosas;

/**
 * It takes two strings, allocates a new string of the correct size, copies the
 * first string into the new string, then copies the second string into the new
 * string
 *
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to the end of s1.
 *
 * @return A pointer to a new string that is the result of the concatenation
 * of s1 and s2.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	t_cosas	c;

	ft_memset(&c, 0, sizeof(t_cosas));
	if (s1 == NULL && s2)
		return (s2);
	if (s2 == NULL && s1)
		return (s1);
	c.l_s1 = ft_strlen(s1);
	c.l_total = c.l_s1 + ft_strlen(s2);
	c.final = ft_calloc(sizeof(char), c.l_total + 1);
	if (c.final == NULL)
		return (NULL);
	while (s1[c.i])
	{
		c.final[c.i] = s1[c.i];
		c.i++;
	}
	while (c.i < c.l_total)
	{
		c.final[c.i] = s2[c.j];
		c.i++;
		c.j++;
	}
	return (c.final);
}
