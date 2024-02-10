/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:53:52 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/10 15:30:01 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	t_info	client;
	char	*msg_binary;
	char	*header;

	parser(argc, argv);
	init_data(argv, &client);
	if (ping(client.server_pid) == 0)
		return (0);
	msg_binary = str_to_binary(client.msg);
	printf("SIZE_MG: [%d]\n", ft_strlen(client.msg));
	header = create_header(msg_binary);
	send_signals(header, &client);
	send_signals(msg_binary, &client);
	free(header);
	free(msg_binary);
	return (0);
}
