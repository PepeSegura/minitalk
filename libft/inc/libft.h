/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:44:42 by psegura-          #+#    #+#             */
/*   Updated: 2023/12/24 22:13:12 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

//LiBFT
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//Funciones LIBFT
int			ft_toupper(int c);
int			ft_tolower(int c);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isxdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);

int			ft_str_is_space(char *str);

int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, int len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);

void		ft_print_matrix(char **matrix, char *str);
void		ft_free_matrix(char **matrix);
int			ft_len_matrix(char **matrix);
void		ft_sort_matrix(char **matrix);
int			ft_locate_str_in_matrix(char **matrix, char *str);
char		**ft_cpy_matrix(char **matrix);
char		**ft_slice_matrix(char **matrix, int start, int end);
char		**ft_add_row_matrix(char **matrix, char *new_row);
char		**ft_delete_row_matrix(char **matrix, int i);

void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

int			ft_atoi(const char *str);
int			ft_atoi_limits(const char *str);
long		ft_atoi_long(const char *str);
long		ft_atol_16(const char *str);
char		*ft_itoa(int n);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

//Funciones GET_NEXT_LINE
char		*get_next_line(int fd);
char		*ft_clean_stash(char *stash);
char		*ft_get_line(char *stash);
char		*ft_get_stash(int fd, char *stash);

int			ft_strlen_gnl(char *str);
char		*ft_strjoin_gnl(char *stash, char *buffer);
char		*ft_strchr_gnl(char *str, int c);
void		*ft_calloc_gnl(size_t count, size_t size);

//Funciones PRINTF
int			ft_printf(char const *string, ...)
			__attribute__((format(printf, 1, 2)));
int			ft_dprintf(int fd, char const *string, ...);

int			ft_putchar_printf(int fd, int c);
int			ft_putstr_printf(int fd, char *str);
int			ft_strlen_printf(char *str);

int			ft_putnbr_base(int fd, size_t nbr, char *b);
int			ft_putnbr(int fd, int n);
int			ft_pointer(int fd, void *p);
void		*ft_print_memory(void *p);

#endif
