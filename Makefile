# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 16:12:27 by psegura-          #+#    #+#              #
#    Updated: 2023/05/18 18:52:33 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###

#RESET	=	\033c
GREEN	=	\033[1;32m
RED		=	\033[0;31m
CYAN	=	\033[0;36m
WHITE	=	\033[0m

NAME_C = client
NAME_S = server

SRCS_C =										\
		srcs/client/client.c					\
		srcs/client/utils.c						\
		srcs/client/init_data.c					\
												\
		
SRCS_S =										\
		srcs/server/server.c					\
		srcs/server/utils.c						\
												\

OBJS_C = $(SRCS_C:%.c=objs/%.o)
OBJS_S = $(SRCS_S:%.c=objs/%.o)

LIB = libft/libft.a

CC = gcc

CFLAGS	 = -Wall -Wextra -Werror -g3 -fsanitize=address,leak
CFLAGS	+= -I inc
CFLAGS	+= -I libft

all: $(NAME_C) $(NAME_S)

$(NAME_C): objs $(OBJS_C)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS_C) $(LIB) -o $(NAME_C)
	@echo "$(CYAN) CLIENT READY$(WHITE)"

$(NAME_S): objs $(OBJS_S)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS_S) $(LIB) -o $(NAME_S)
	@echo "$(CYAN) SERVER READY$(WHITE)"

objs:
	@mkdir -p objs/srcs/server objs/srcs/client

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -rf objs

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME_C)
	@rm -f $(NAME_S)

re: fclean all

norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma
