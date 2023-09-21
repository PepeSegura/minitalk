/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:25:49 by psegura-          #+#    #+#             */
/*   Updated: 2023/09/20 16:39:12 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	append_char_bits_to_string(char c, char *string, int *index)
{
	int	k;

	k = 7;
	while (k >= 0)
	{
		if (c & (1 << k))
			string[*index] = '1';
		else
			string[*index] = '0';
		(*index)++;
		k--;
	}
}

char	*conver_str_to_bits(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	len = ft_strlen(str) * 8;
	result = malloc(len + 1);
	if (!result)
		exit(1);
	j = 0;
	i = 0;
	while (str[i])
	{
		append_char_bits_to_string(str[i], result, &j);
		i++;
	}
	result[j] = '\0';
	return (result);
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

void	ft_print_error(char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_perror(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

char	*nbr_to_header(int num, int size)
{
	int		temp;
	int		len;
	char	*binary;
	int		i;

	temp = num;
	len = 0;
	while (temp > 0)
	{
		temp = temp / 2;
		len++;
	}
	binary = (char *)calloc((size + 1) , sizeof(char));
	for (int i = 0; i < size - len; i++)
	{
		binary[i] = '0';
	}
	i = size - 1;
	while (num > 0)
	{
		if (num % 2 == 0)
			binary[i] = '0';
		else
			binary[i] = '1';
		num = num / 2;
		i--;
	}
	return (binary);
}
