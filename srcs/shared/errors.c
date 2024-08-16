/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:15:05 by psegura-          #+#    #+#             */
/*   Updated: 2024/08/17 00:15:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	ft_print_error(char *error_msg)
{
	ft_dprintf(2, "Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}
