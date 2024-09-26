/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:52 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/26 16:23:27 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_global	g_server;

int	main(int argc, char **argv)
{
	t_client	data;
	int			msg_len;

	parser(argc, argv);
	init_data(argv, &data);
	if (ping(data.server_pid) == 0)
		return (0);
	msg_len = ft_strlen(argv[2]);
	ft_printf("MSG_LEN: [%d]\n", msg_len);
	send_signals(&msg_len, 32, &data);
	send_message(data.msg, &data);
	return (0);
}
