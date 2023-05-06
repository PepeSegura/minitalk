/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:58:49 by psegura-          #+#    #+#             */
/*   Updated: 2022/08/15 02:55:31 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function returns the length of the first word in a string
 * 
 * @param s The string to be split.
 * @param c the character to split the string by
 * 
 * @return The length of the word. 
 */
static int	ft_lword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

/**
 * It counts the number of words in a string
 * 
 * @param s The string to be split.
 * @param c the character to be used as a delimiter
 * 
 * @return The number of words in the string.
 */
static int	ft_cword(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			cont++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (cont);
}

/**
 * It frees the memory allocated for the matrix
 * 
 * @param matrix the matrix to be freed
 * @param pos the position of the matrix that we want to free
 * 
 * @return A pointer to a pointer to a char.
 */
static char	**ft_free(char **matrix, int pos)
{
	while (pos >= 0)
	{
		free(matrix[pos]);
		pos--;
	}
	free(matrix);
	return (NULL);
}

/**
 * It splits a string into an array of strings, using a given character as a
 * delimiter
 * 
 * @param s The string to be split.
 * @param c the character to split the string by
 * 
 * @return A pointer to a newly allocated space in memory which contains a copy
 * of the string given as argument.
 */
char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		c_word;
	int		p_word;
	int		i;

	if (!s)
		return (NULL);
	c_word = ft_cword(s, c);
	matrix = (char **)malloc(sizeof(char *) * (c_word + 1));
	if (!matrix)
		return (NULL);
	matrix[c_word] = NULL;
	p_word = 0;
	i = 0;
	while (p_word < c_word)
	{
		while (s[i] == c)
			i++;
		matrix[p_word] = ft_substr(s, i, ft_lword(s + i, c));
		if (!matrix[p_word])
			return (ft_free(matrix, p_word));
		i += ft_lword(s + i, c);
		p_word++;
	}
	return (matrix);
}
