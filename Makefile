# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 16:12:27 by psegura-          #+#    #+#              #
#    Updated: 2024/09/23 18:45:00 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

### Colors ###

GREEN	=	\033[1;32m
RED		=	\033[0;31m
CYAN	=	\033[0;36m
WHITE	=	\033[0m

NAME_C = client
NAME_S = server

SHARED =					\
			errors.c		\

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
			server/pong.c			\
			$(SRCS_SHARED)			\

SRCS_S = $(addprefix srcs/, $(SERVER))

OBJS_C = $(SRCS_C:%.c=objs/%.o)
OBJS_S = $(SRCS_S:%.c=objs/%.o)

LIB = libft/libft.a

CC = cc

CFLAGS	 = -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address
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

.PHONY: all clean fclean re norma debug
