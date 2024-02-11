/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_row_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:48:53 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/11 10:43:18 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_delete_row_matrix(char **matrix, int delete)
{
	char	**new_matrix;
	int		len_matrix;
	int		i;
	int		j;

	if (!matrix)
		return (NULL);
	len_matrix = ft_len_matrix(matrix);
	if (delete < 0 || delete > len_matrix)
		return (matrix);
	new_matrix = ft_calloc(ft_len_matrix(matrix), sizeof(char *));
	if (!new_matrix)
		return (NULL);
	i = 0;
	j = 0;
	while (matrix[j])
	{
		if (i == delete)
			j++;
		new_matrix[i] = matrix[j];
		i++;
		j++;
	}
	free(matrix);
	return (new_matrix);
}

// int main(void)
// {
// 	char **aux = ft_calloc(sizeof(char *), 4);

// 	aux[0] = ft_strdup("hola");
// 	aux[1] = ft_strdup("que");
// 	aux[2] = ft_strdup("tal");

// 	ft_print_matrix(aux, "old");

// 	char **new = ft_delete_row_matrix(aux, 3);

// 	ft_print_matrix(new, "new");
// }
