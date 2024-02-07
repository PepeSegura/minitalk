/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_row_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:49:01 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/11 19:03:20 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_row_matrix(char **matrix, char *new_row)
{
	int		i;
	char	**aux;

	if (!matrix)
		return (NULL);
	aux = ft_calloc(sizeof(char *), (ft_len_matrix(matrix) + 2));
	if (!aux)
		return (NULL);
	if (!new_row)
		return (matrix);
	i = 0;
	while (i < ft_len_matrix(matrix))
	{
		aux[i] = matrix[i];
		i++;
	}
	aux[i] = new_row;
	free(matrix);
	return (aux);
}
