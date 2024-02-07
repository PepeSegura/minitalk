/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:00:27 by pepe              #+#    #+#             */
/*   Updated: 2023/07/17 16:43:39 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE "0123456789abcdef"

void	print_first_colum(void *p)
{
	ft_printf("%p: ", p);
}

void	print_middle_column(void *p)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)p;
	while (str[i] && i < 16)
	{
		write(1, &BASE[str[i] / 16], 1);
		write(1, &BASE[str[i] % 16], 1);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	print_last_column(void *addr)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)addr;
	while (str[i] && i < 16)
	{
		if (str[i] >= 32 && str[i] < 127)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr)
{
	int		count;
	int		size;
	char	*str;

	count = 0;
	str = (char *)addr;
	size = ft_strlen(addr);
	while (count < size)
	{
		print_first_colum(str);
		print_middle_column(str);
		print_last_column(str);
		str += 16;
		count += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
