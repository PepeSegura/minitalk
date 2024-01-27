/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_limits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:56:18 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/27 10:41:53 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_error(const char *str)
{
	ft_dprintf(2, "Error:\n\t%s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_atoi_limits(const char *str)
{
	int		i;
	long	dest;
	int		sign;

	i = 0;
	dest = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		dest = (dest * 10) + (str[i++] - '0');
	if ((dest * sign) > INT_MAX || (dest * sign) < INT_MIN)
		print_error("Overflow detected");
	return ((int)(dest * sign));
}
