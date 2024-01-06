/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:14:56 by psegura-          #+#    #+#             */
/*   Updated: 2023/06/12 05:38:27 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

long	ft_atoi_long(const char *str)
{
	int				i;
	long long int	dest;
	int				sign;

	i = 0;
	dest = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-'
			|| str[i + 1] == '+'))
		return (0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		dest = dest * 10;
		dest = dest + str[i] - 48;
		i++;
	}
	return (dest * sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	dest;
	int				sign;

	i = 0;
	dest = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-'
			|| str[i + 1] == '+'))
		return (0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		dest = dest * 10;
		dest = dest + str[i] - 48;
		i++;
	}
	return (dest * sign);
}

long long int	atol_16_aux(const char *str, int *i)
{
	long long int	dest;

	dest = 0;
	while (ft_isxdigit(str[*i]))
	{
		dest = dest * 16;
		if (ft_isdigit(str[*i]))
			dest = dest + str[*i] - '0';
		else
			dest = dest + ft_toupper(str[*i]) - 'A' + 10;
		(*i)++;
	}
	return (dest);
}

long	ft_atol_16(const char *str)
{
	int				i;
	long long int	dest;
	int				sign;

	i = 0;
	dest = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-'
			|| str[i + 1] == '+'))
		return (0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	dest = atol_16_aux(str, &i);
	return (dest * sign);
}
