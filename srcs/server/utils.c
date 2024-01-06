/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:39:06 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/06 19:22:41 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	keep_server_up(void)
{
	while (1)
		sleep(1);
}

void	ft_print_error(char *error_msg)
{
	ft_dprintf(2, "Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}

char	*binary_to_ascii(char *binary_string)
{
	int		len;
	int		num_chunks;
	char	*ascii_string;
	char	chunk[9];
	int		ascii_val;

	len = strlen(binary_string);
	num_chunks = len / 8;
	ascii_string = (char *)malloc(num_chunks + 1);
	for (int i = 0; i < num_chunks; i++)
	{
		strncpy(chunk, binary_string + i * 8, 8);
		chunk[8] = '\0';
		ascii_val = strtol(chunk, NULL, 2);
		ascii_string[i] = (char)ascii_val;
	}
	ascii_string[num_chunks] = '\0';
	return (ascii_string);
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

int	binary_to_int(char *binary)
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
