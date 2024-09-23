/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:49 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/23 18:49:11 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

inline int	get_bit_value(int signum)
{
	if (signum == SIGUSR1)
		return (0);
	return (1);
}

void	memory_reserve_to_store_signals(int *i)
{
	ft_printf("SIZE_MSG: [%d]\n", g_client.msg.size_message);
	g_client.msg.message = malloc((g_client.msg.size_message + 1) * 1);
	if (g_client.msg.message == NULL)
		ft_print_error("Malloc_failed");
	g_client.getting_header = 0;
	g_client.getting_msg = 1;
	(*i) = 0;
}

void	handle_header(int *i, int signum)
{
	const int	bit_value = get_bit_value(signum);

	if ((*i) < HEADER_SIZE)
	{
		g_client.msg.size_message |= (bit_value << (HEADER_SIZE - 1 - (*i)));
		(*i)++;
	}
	if ((*i) == HEADER_SIZE)
		memory_reserve_to_store_signals(i);
}

inline void	print_msg(void)
{
	write(1, HEADER_MESSAGE, 18);
	write(1, g_client.msg.message, g_client.msg.size_message);
	write(1, "\n", 1);
}

void	handle_msg(int *i, int signum)
{
	const int	bit_value = get_bit_value(signum);
	static int	char_value;
	static int	msg_pos;

	if (*i % 8 < 8)
	{
		char_value |= (bit_value << (7 - (*i % 8)));
		(*i)++;
	}
	if (*i % 8 == 0)
	{
		g_client.msg.message[msg_pos] = char_value;
		char_value = 0;
		msg_pos++;
	}
	if (*i / 8 == g_client.msg.size_message)
	{
		print_msg();
		free(g_client.msg.message);
		ft_bzero(&g_client, sizeof(g_client));
		g_client.getting_header = 1;
		(*i) = 0;
		msg_pos = 0;
	}
}
