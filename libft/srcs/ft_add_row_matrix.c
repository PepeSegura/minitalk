/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_row_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:49:01 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/04 23:35:40 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_row_matrix(char **matrix, char *new_row)
{
	int		i;
	char	**aux;

	if (!matrix)
		return (NULL);
	if (!new_row)
		return (matrix);
	aux = ft_calloc(sizeof(char *), (ft_len_matrix(matrix) + 2));
	if (!aux)
		return (NULL);
	i = 0;
	while (i < ft_len_matrix(matrix))
	{
		aux[i] = malloc(sizeof(char) * (ft_strlen(matrix[i]) + 1));
		if (!aux[i])
			return (ft_free_matrix(aux), NULL);
		ft_strncpy(aux[i], matrix[i], ft_strlen(matrix[i]) + 1);
		i++;
	}
	aux[i] = ft_calloc(sizeof(char), (ft_strlen(new_row) + 1));
	if (!aux[i])
		return (ft_free_matrix(aux), NULL);
	ft_strncpy(aux[i++], new_row, ft_strlen(new_row) + 1);
	return (aux);
}
