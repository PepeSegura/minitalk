# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 16:12:27 by psegura-          #+#    #+#              #
#    Updated: 2024/01/27 10:14:49 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

### Colors ###

#RESET	=	\033c
GREEN	=	\033[1;32m
RED		=	\033[0;31m
CYAN	=	\033[0;36m
WHITE	=	\033[0m

NAME_C = client
NAME_S = server

SHARED =					\
			errors.c		\
			utils.c			\
			binary_to_x.c	\
			x_to_binary.c	\

SRCS_SHARED = $(addprefix shared/, $(SHARED))

CLIENT =							\
			client/main.c			\
			client/client.c			\
			client/parser.c			\
			client/ping.c			\
			$(SRCS_SHARED)			\
		
SRCS_C = $(addprefix srcs/, $(CLIENT))

SERVER =							\
			server/main.c			\
			server/server.c			\
			$(SRCS_SHARED)			\

SRCS_S = $(addprefix srcs/, $(SERVER))

OBJS_C = $(SRCS_C:%.c=objs/%.o)
OBJS_S = $(SRCS_S:%.c=objs/%.o)

LIB = libft/libft.a

CC = gcc

CFLAGS	 = -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS	+= -I inc
CFLAGS	+= -I libft

all: $(NAME_C) $(NAME_S)

$(NAME_C): objs $(OBJS_C)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS_C) $(LIB) -o $(NAME_C)
	@echo "$(CYAN)CLIENT READY$(WHITE)"

$(NAME_S): objs $(OBJS_S)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS_S) $(LIB) -o $(NAME_S)
	@echo "$(CYAN)SERVER READY$(WHITE)"

objs:
	@mkdir -p objs/srcs/server objs/srcs/client objs/srcs/shared

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -rf objs

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME_C)
	@rm -f $(NAME_S)

re:: fclean
re:: all

debug:: CFLAGS += -g3 -fsanitize=address#,leak
debug:: re

norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma debug
