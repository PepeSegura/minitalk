/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_to_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:45:29 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/07 20:44:39 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

char	*str_to_binary(char *str)
{
	int		i;
	int		j;
	int		bite;
	char	*binary;

	binary = ft_calloc(((ft_strlen(str) * 8) + 1), sizeof(char));
	if (!binary)
		ft_print_error("malloc failed.");
	j = 0;
	i = 0;
	while (str[i])
	{
		bite = 8;
		while (bite--)
			binary[j++] = (str[i] >> bite & 1) + '0';
		i++;
	}
	return (binary);
}

static int	get_nbr_len(int nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr >> 1;
		len++;
	}
	return (len);
}

static void	fill_leading_zeros(char *str, int size, int len)
{
	int	i;

	i = -1;
	while (++i < size - len)
		str[i] = '0';
}

char	*int_to_binary(int nbr, int size)
{
	char	*binary;
	int		i;

	binary = ft_calloc((size + 1), sizeof(char));
	if (!binary)
		ft_print_error("malloc failed.");
	fill_leading_zeros(binary, size, get_nbr_len(nbr));
	i = size - 1;
	while (nbr > 0)
	{
		if (nbr % 2 == 0)
			binary[i] = '0';
		else
			binary[i] = '1';
		nbr = nbr >> 1;
		i--;
	}
	return (binary);
}
