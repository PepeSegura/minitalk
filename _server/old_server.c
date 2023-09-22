/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:45:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/09/22 22:40:17 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_s;

// unsigned char	binary_to_ascii(char *binary_string)
// {
// 	char	chunk[9];
// 	int		ascii_val;

// 	strncpy(chunk, binary_string, 8);
// 	chunk[8] = '\0';
// 	ascii_val = strtol(chunk, NULL, 2);
// 	return ((unsigned char)ascii_val);
// }

char	*binary_to_ascii(char *binary_string)
{
	int		len;
	int		num_chunks;
	char	*ascii_string;
	int		i;
	char	chunk[9];
	int		j;
	int		index;
	int		ascii_val;

	len = strlen(binary_string);
	num_chunks = len / 8;
	if (len % 8 != 0)
	{
		num_chunks++;
	}
	ascii_string = (char *)malloc(num_chunks + 1);
	ascii_string[num_chunks] = '\0';
	for (i = 0; i < num_chunks; i++)
	{
		for (j = 0; j < 8; j++)
		{
			index = i * 8 + j;
			if (index < len)
				chunk[j] = binary_string[index];
			else
				chunk[j] = '0';
		}
		chunk[8] = '\0';
		ascii_val = strtol(chunk, NULL, 2);
		ascii_string[i] = (char)ascii_val;
	}
	return (ascii_string);
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
	if (sig == SIGUSR1)
	{
		if (g_s.len < 32)
		{
			g_s.size_next[g_s.len] = '0';
			g_s.len++;
		}
		if (g_s.len == 32)
		{
			g_s.int_next = binaryToInt(g_s.size_next);
			memset(g_s.size_next, 0, sizeof(g_s.size_next));
			g_s.msg = malloc((g_s.int_next + 1) * sizeof(char));
			if (!g_s.msg)
				exit(1);
			g_s.len++;
		}
		else if (g_s.len >= 32 && g_s.len <= g_s.int_next + 32)
		{
			g_s.msg[g_s.len - 33] = '0';
			g_s.len++;
		}
		if (g_s.len > g_s.int_next + 32)
		{
			g_s.msg[g_s.len - 33] = '\0';
			g_s.len = 0;
			g_s.result = binary_to_ascii(g_s.msg);
			write(1, g_s.result, g_s.int_next / 8);
			write(1, "\n", 1);
		}
	}
}

void	handle_sigusr2(int sig)
{
	if (sig == SIGUSR2)
	{
		if (g_s.len < 32)
		{
			g_s.size_next[g_s.len] = '1';
			g_s.len++;
		}
		if (g_s.len == 32)
		{
			g_s.int_next = binaryToInt(g_s.size_next);
			memset(g_s.size_next, 0, sizeof(g_s.size_next));
			g_s.msg = malloc((g_s.int_next + 1) * sizeof(char));
			if (!g_s.msg)
				exit(1);
			g_s.len++;
		}
		else if (g_s.len >= 32 && g_s.len <= g_s.int_next + 32)
		{
			g_s.msg[g_s.len - 33] = '1';
			g_s.len++;
		}
		if (g_s.len > g_s.int_next + 32)
		{
			g_s.msg[g_s.len - 33] = '\0';
			g_s.len = 0;
			g_s.result = binary_to_ascii(g_s.msg);
			write(1, g_s.result, g_s.int_next / 8);
			write(1, "\n", 1);
		}
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
