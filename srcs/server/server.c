/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:45:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/09 00:20:40 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_cosas			g_c;

// unsigned char	binary_to_ascii(char *binary_string)
// {
// 	char	chunk[9];
// 	int		ascii_val;

// 	strncpy(chunk, binary_string, 8);
// 	chunk[8] = '\0';
// 	ascii_val = strtol(chunk, NULL, 2);
// 	return ((unsigned char)ascii_val);
// }

char *binary_to_ascii(char *binary_string) {
    int len = strlen(binary_string);
    int num_chunks = len / 8;
    if (len % 8 != 0) {
        num_chunks++;
    }
    char *ascii_string = (char*) malloc(num_chunks + 1);
    ascii_string[num_chunks] = '\0';
    int i;
    for (i = 0; i < num_chunks; i++) {
        char chunk[9];
        int j;
        for (j = 0; j < 8; j++) {
            int index = i * 8 + j;
            if (index < len) {
                chunk[j] = binary_string[index];
            } else {
                chunk[j] = '0';
            }
        }
        chunk[8] = '\0';
        int ascii_val = strtol(chunk, NULL, 2);
        ascii_string[i] = (char) ascii_val;
    }
    return ascii_string;
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
		// printf("g_c.len -> %d\n", g_c.len);
		if (g_c.len < 32)
		{
			g_c.size_next[g_c.len] = '0';
			g_c.len++;
		}
		if (g_c.len == 32)
		{
			g_c.int_next = binaryToInt(g_c.size_next);
			// printf("SIZE_NEXT_MSG_BIN: [%s] DEC: [%d]\n", g_c.size_next,
					// g_c.int_next);
			memset(g_c.size_next, 0, sizeof(g_c.size_next));
			g_c.msg = malloc((g_c.int_next + 1) * sizeof(char));
			if (!g_c.msg)
				exit(1);
			g_c.len++;
		}
		else if (g_c.len >= 32 && g_c.len <= g_c.int_next + 32)
		{
			// printf("INICIO MENSAGE: %d\n", g_c.len);
			g_c.msg[g_c.len - 33] = '0';
			g_c.len++;
		}
		if (g_c.len > g_c.int_next + 32)
		{
			g_c.msg[g_c.len - 33] = '\0';
			g_c.len = 0;
			g_c.result = binary_to_ascii(g_c.msg);
			write(1, g_c.result, g_c.int_next / 8);
			write(1, "\n", 1);
			// write(1, "\nEND_OF_MESSAGE\n", 16);
		}
	}
}

void	handle_sigusr2(int sig)
{
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
			g_c.int_next = binaryToInt(g_c.size_next);
			// printf("SIZE_NEXT_MSG_BIN: [%s] DEC: [%d]\n", g_c.size_next,
			// 		g_c.int_next);
			memset(g_c.size_next, 0, sizeof(g_c.size_next));
			g_c.msg = malloc((g_c.int_next + 1) * sizeof(char));
			if (!g_c.msg)
				exit(1);
			g_c.len++;
		}
		else if (g_c.len >= 32 && g_c.len <= g_c.int_next + 32)
		{
			// printf("INICIO MENSAGE: %d\n", g_c.len);
			g_c.msg[g_c.len - 33] = '1';
			g_c.len++;
		}
		if (g_c.len > g_c.int_next + 32)
		{
			g_c.msg[g_c.len - 33] = '\0';
			g_c.len = 0;
			g_c.result = binary_to_ascii(g_c.msg);
			write(1, g_c.result, g_c.int_next / 8);
			write(1, "\n", 1);
			// write(1, "\nEND_OF_MESSAGE\n", 16);
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
