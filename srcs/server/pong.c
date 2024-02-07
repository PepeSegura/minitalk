/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 09:56:37 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/07 21:21:59 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

#define SERVER_READY SIGUSR1
#define SERVER_BUSY SIGUSR2

int	pong(int pid)
{
	kill(pid, SERVER_READY);
	g_client.actual_pid = pid;
	return (g_client.is_ready);
}
