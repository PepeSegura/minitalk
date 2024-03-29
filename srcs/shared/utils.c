/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:25:49 by psegura-          #+#    #+#             */
/*   Updated: 2024/01/26 17:46:30 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	print_bytes(char *str)
{
	int	i;

	write(1, "binary text:", 12);
	i = 0;
	while (str[i])
	{
		if (i % 8 == 0)
			write(1, " ", 1);
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
