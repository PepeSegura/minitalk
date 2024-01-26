/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_to_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:44:24 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/26 17:44:59 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	binary_to_int(char *binary)
{
	int	nbr;
	int	pos;
	int	i;

	nbr = 0;
	pos = 1;
	i = ft_strlen(binary) - 1;
	while (i > 0)
	{
		if (binary[i] == '1')
			nbr = nbr + pos;
		i--;
		pos = pos << 1;
	}
	return (nbr);
}

static char	create_letter(char *str)
{
	unsigned char	c;
	int				i;

	i = 0;
	c = 0;
	while (i < 8)
	{
		if (str[i] == '1')
			c |= (1 << (7 - i));
		i++;
	}
	return (c);
}

char	*binary_to_str(char *binary)
{
	char	*str;
	int		i;
	int		j;

	str = ft_calloc((ft_strlen(binary) / 8) + 1, sizeof(char));
	if (!str)
		ft_print_error("malloc failed.");
	i = 0;
	j = 0;
	while (binary[i])
	{
		if (i % 8 == 0)
			str[j++] = create_letter(binary + i);
		i++;
	}
	return (str);
}
