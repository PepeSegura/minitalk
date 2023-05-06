/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:13:50 by psegura-          #+#    #+#             */
/*   Updated: 2023/03/25 04:22:00 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = ft_len_matrix(matrix);
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
}

void	ft_free_matrix2(char **matrix)
{
	int	i;

	i = ft_len_matrix(matrix);
	while (--i >= 0)
	{
		if (ft_strlen(matrix[i]))
		{
			ft_putstr_fd("matrix [", 2);
			ft_putstr_fd(matrix[i], 2);
			ft_putstr_fd("]\n", 2);
			free(matrix[i]);
		}
	}
	free(matrix);
}
