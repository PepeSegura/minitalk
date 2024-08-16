/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:52 by psegura-          #+#    #+#             */
/*   Updated: 2024/08/16 23:47:16 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	(void)argc, (void)argv;
	t_info	client;
	int	msg_len;

	parser(argc, argv);
	init_data(argv, &client);
	if (ping(client.server_pid) == 0)
		return (0);
	msg_len = ft_strlen(argv[2]);
	printf("MSG_LEN: [%d]\n", msg_len);
	send_signals(&msg_len, 32, &client);
	send_message(client.msg, &client);
	return (0);
}
