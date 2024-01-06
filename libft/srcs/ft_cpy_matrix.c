/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:52:23 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/06 13:59:44 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cpy_matrix(char **matrix)
{
	char	**aux;
	int		i;

	if (!matrix)
		return (NULL);
	aux = malloc(sizeof(char *) * (ft_len_matrix(matrix) + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		aux[i] = ft_strdup(matrix[i]);
		if (!aux[i])
			return (ft_free_matrix(aux), NULL);
		i++;
	}
	aux[i] = NULL;
	ft_free_matrix(matrix);
	return (aux);
}

char	**ft_slice_matrix(char **matrix, int start, int end)
{
	char	**aux;
	int		i;

	if (!matrix || start > end || ft_len_matrix(matrix) < end)
		return (NULL);
	aux = malloc(sizeof(char *) * (end - start + 2));
	if (!aux)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		aux[i] = ft_strdup(matrix[start]);
		if (!aux[i])
			return (ft_free_matrix(aux), NULL);
		i++;
		start++;
	}
	aux[i] = NULL;
	return (aux);
}
