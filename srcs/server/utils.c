/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:41:43 by pepe              #+#    #+#             */
/*   Updated: 2023/07/16 13:49:46 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*decimalToBinary(int num)
{
	int		temp;
	int		len;
	int		MAX_BITS;
	char	*binary;
	int		i;

	temp = num;
	len = 0;
	MAX_BITS = 32;
	while (temp > 0)
	{
		temp = temp / 2;
		len++;
	}
	binary = (char *)malloc((MAX_BITS + 1) * sizeof(char));
	for (int i = 0; i < MAX_BITS - len; i++)
	{
		binary[i] = '0';
	}
	i = MAX_BITS - 1;
	while (num > 0)
	{
		if (num % 2 == 0)
			binary[i] = '0';
		else
			binary[i] = '1';
		num = num / 2;
		i--;
	}
	binary[MAX_BITS] = '\0';
	return (binary);
}

double	my_pow(double x, int n)
{
	double	result;
	int		i;

	result = 1;
	i = 0;
	while (i < n)
	{
		result *= x;
		i++;
	}
	return (result);
}

int	binaryToInt(char *binary)
{
	int	result;
	int	len;
	int	i;

	result = 0;
	len = strlen(binary);
	i = 0;
	while (i < len)
	{
		if (binary[i] == '1')
		{
			result += my_pow(2, len - i - 1);
		}
		i++;
	}
	return (result);
}
