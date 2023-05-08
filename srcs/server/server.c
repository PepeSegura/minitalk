/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:45:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/08 14:25:51 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_cosas	g_c;

unsigned char binary_to_ascii(char *binary_string) {
    char chunk[9];
    strncpy(chunk, binary_string, 8);
    chunk[8] = '\0';
    int ascii_val = strtol(chunk, NULL, 2);
    return ((unsigned char) ascii_val);
}

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

void	handle_sigusr1(int sig)
{
	// unsigned char	letter;


	if (sig == SIGUSR1)
	{
		// printf("g_c.len -> %d\n", g_c.len);
		if (g_c.len < 32)
		{
			g_c.size_next[g_c.len] = '0';
			g_c.len++;
		}
		if (g_c.len == 32)
		{
			printf("SIZE_NEXT_MSG_BIN: [%s] DEC: [%d]\n", g_c.size_next, binaryToInt(g_c.size_next));
			g_c.len = 0;
			memset(g_c.size_next, 0, sizeof(g_c.size_next));
			// exit(0);
		}
		// else
		// 	g_c.len++;
	}

}

void	handle_sigusr2(int sig)
{
	// unsigned char	letter;

	if (sig == SIGUSR2)
	{
		// printf("g_c.len -> %d\n", g_c.len);
		if (g_c.len < 32)
		{
			g_c.size_next[g_c.len] = '1';
			g_c.len++;
		}
		if (g_c.len == 32)
		{
			printf("SIZE_NEXT_MSG_BIN: [%s] DEC: [%d]\n", g_c.size_next, binaryToInt(g_c.size_next));
			g_c.len = 0;
			memset(g_c.size_next, 0, sizeof(g_c.size_next));
			// exit(0);
		}
		// else
		// 	g_c.len++;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	print_pid();
	keep_server_up();
	return (0);
}
