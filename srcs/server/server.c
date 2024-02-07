/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:01:51 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/07 21:40:24 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	set_input(int signum)
{
	if (signum == SIGUSR1)
		return ('0');
	else
		return ('1');
}

void	store_signals_for_header(int *i, char input)
{
	g_client.msg.header[(*i)] = input;
	(*i)++;
}

void	memory_reserve_to_store_signals(int *i)
{
	g_client.msg.size_message = binary_to_int(g_client.msg.header);
	ft_memset(&g_client.msg.header, 0, sizeof(g_client.msg.header));
	g_client.msg.message = ft_calloc((g_client.msg.size_message + 1), 1);
	if (g_client.msg.message == NULL)
		ft_print_error("Malloc_failed");
	(*i)++;
}

void	store_signals(int *i, char input)
{
	g_client.msg.message[(*i) - 33] = input;
	(*i)++;
}

void	create_and_print_final_message(int *i)
{
	char	*hole_msg;

	hole_msg = binary_to_str(g_client.msg.message);
	free(g_client.msg.message);
	write(1, hole_msg, g_client.msg.size_message / 8);
	write(1, "\n", 1);
	g_client.actual_pid = 0;
	free(hole_msg);
	(*i) = 0;
}
