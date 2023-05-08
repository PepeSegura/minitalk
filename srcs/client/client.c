/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 20:44:32 by psegura-          #+#    #+#             */
/*   Updated: 2023/05/07 21:26:44 by pepe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	append_char_bits_to_string(char c, char *string, int *index)
{
	int	k;

	k = 7;
	while (k >= 0)
	{
		if (c & (1 << k))
			string[*index] = '1';
		else
			string[*index] = '0';
		(*index)++;
		k--;
	}
}

char	*conver_str_to_bits(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	len = ft_strlen(str) * 8;
	result = malloc(len + 1);
	if (!result)
		exit(1);
	j = 0;
	i = 0;
	while (str[i])
	{
		append_char_bits_to_string(str[i], result, &j);
		i++;
	}
	result[j] = '\0';
	return (result);
}

int	parse_input(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf(USAGE);
		exit(EXIT_FAILURE);
	}
	return (ft_atoi(argv[1]));
}

void	send_signals(int server_pid,  char *str)
{
	int	i = 0;
	
	while (str[i])
	{
		if (str[i] == '0')
			kill(server_pid, SIGUSR1);
		if (str[i] == '1')
			kill(server_pid, SIGUSR2);
		i++;
		usleep(300);
	}
}

char *binary_to_ascii(char *binary_string) {
    int len = strlen(binary_string);
    int num_chunks = len / 8;
    char *ascii_string = (char*) malloc(num_chunks + 1);

    for (int i = 0; i < num_chunks; i++) {
        char chunk[9];
        strncpy(chunk, binary_string + i*8, 8);
        chunk[8] = '\0';
        int ascii_val = strtol(chunk, NULL, 2);
        ascii_string[i] = (char) ascii_val;
    }
    ascii_string[num_chunks] = '\0';
    return (ascii_string);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str_binary;
	char	*msg_binary_size;

	server_pid = parse_input(argc, argv);
	printf("Server_PID: [%d]\n", server_pid);
	str_binary = conver_str_to_bits(argv[2]);
	// printf("%s\n", str_binary);
	

	int message_size = strlen(str_binary);
	// char size_str[32]; // assuming message size will fit in 32 bytes
	msg_binary_size = decimalToBinary(message_size);
	printf("MSG_SIZE:[%d]\nINT->BINARY:[%s]\n", message_size, msg_binary_size);

	printf("BINARY->INT: [%d]\n", binaryToInt(msg_binary_size));
	send_signals(server_pid, msg_binary_size); // send message size first
	// send_signals(server_pid, argv[2]); // send message next

	// send_signals(server_pid, str_binary);

	free(str_binary);
	free(msg_binary_size);
	return (0);
}
