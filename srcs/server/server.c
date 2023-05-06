/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:45:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/06 21:01:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID_SERVER: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putendl_fd("", 1);
}

void	keep_server_up(void)
{
	while (1)
		sleep(1);
}

int	main(void)
{
	print_pid();
	keep_server_up();
	return (0);
}
