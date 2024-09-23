/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:56:37 by psegura-          #+#    #+#             */
/*   Updated: 2024/09/23 23:15:30 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

#define SERVER_READY SIGUSR1
#define SERVER_BUSY SIGUSR2

int	pong(int pid)
{
	kill(pid, SERVER_READY);
	g_client.actual_pid = pid;
	g_client.getting_header = 1;
	return (EXIT_SUCCESS);
}
