# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 20:21:59 by psegura-          #+#    #+#              #
#    Updated: 2023/12/24 23:09:00 by psegura-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Colors ###

RESET	=	\033c
GREEN	=	\033[1;32m
RED		=	\033[0;31m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = libft.a

SRCS = 								\
	srcs/ft_toupper.c				\
	srcs/ft_tolower.c				\
									\
	srcs/ft_isalpha.c				\
	srcs/ft_isdigit.c				\
	srcs/ft_isalnum.c				\
	srcs/ft_isascii.c				\
	srcs/ft_isprint.c				\
	srcs/ft_isspace.c				\
									\
	srcs/ft_str_is_space.c			\
									\
	srcs/ft_strlen.c				\
	srcs/ft_strcpy.c				\
	srcs/ft_strlcat.c				\
	srcs/ft_strchr.c				\
	srcs/ft_strrchr.c				\
	srcs/ft_strncmp.c				\
	srcs/ft_strnstr.c				\
	srcs/ft_strjoin.c				\
	srcs/ft_strmapi.c				\
	srcs/ft_striteri.c				\
	srcs/ft_strdup.c				\
	srcs/ft_strndup.c				\
									\
	srcs/ft_memset.c				\
	srcs/ft_memcpy.c				\
	srcs/ft_memmove.c				\
	srcs/ft_memchr.c				\
	srcs/ft_memcmp.c				\
									\
	srcs/ft_print_matrix.c			\
	srcs/ft_free_matrix.c			\
	srcs/ft_len_matrix.c			\
	srcs/ft_sort_matrix.c			\
	srcs/ft_locate_str_in_matrix.c	\
	srcs/ft_cpy_matrix.c			\
	srcs/ft_add_row_matrix.c		\
	srcs/ft_delete_row_matrix.c		\
									\
	srcs/ft_bzero.c					\
	srcs/ft_calloc.c				\
									\
	srcs/ft_substr.c				\
	srcs/ft_strtrim.c				\
	srcs/ft_split.c					\
									\
	srcs/ft_atoi.c					\
	srcs/ft_atoi_limits.c			\
	srcs/ft_itoa.c					\
									\
	srcs/ft_putchar_fd.c			\
	srcs/ft_putstr_fd.c				\
	srcs/ft_putendl_fd.c			\
	srcs/ft_putnbr_fd.c				\
									\
	srcs/ft_lstnew.c				\
	srcs/ft_lstadd_front.c			\
	srcs/ft_lstsize.c				\
	srcs/ft_lstlast.c				\
	srcs/ft_lstadd_back.c			\
	srcs/ft_lstdelone.c				\
	srcs/ft_lstclear.c				\
	srcs/ft_lstiter.c				\
	srcs/ft_lstmap.c				\
									\
	srcs/get_next_line.c			\
	srcs/get_next_line_utils.c		\
									\
	srcs/ft_printf.c				\
	srcs/ft_putnbr_base.c			\
	srcs/ft_printf_utils.c			\
	srcs/ft_print_memory.c			\

OBJS = $(SRCS:%.c=objs/%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I inc

$(NAME): objs $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(CLEAR)$(CYAN)Libft Done!$(WHITE)"
	@tput cnorm

objs:
	@mkdir -p objs/srcs

objs/%.o: %.c
	@tput civis
	@printf "$(CLEAR)$(RED)\t$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(NAME)

re: fclean all

norma:
	@echo 6e6f726d696e65747465207372637320696e6320313e2f6465762f6e756c6c3b206966205b5b20243f202d65712030205d5d3b207468656e206e6f726d696e65747465207372637320696e633b20656c7365206e6f726d696e65747465207372637320696e63207c206772657020274572726f7227203b206669 | xxd -r -p | zsh

.PHONY: all clean fclean re norma
