/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 10:27:51 by mfornah           #+#    #+#             */
/*   Updated: 2023/04/01 19:14:50 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <ctype.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int str);
int					ft_isdigit(int str);
int					ft_isalnum(int str);
int					ft_isprint(int str);
int					ft_isascii(int str);

size_t				ft_strlen(const char *str);
void				*ft_memset(void *dest, int ch, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *str1, const void *str2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, unsigned int nb);

int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
void				ft_putstr_fd(char *s, int fd);

void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);

void				ft_putstr(char *str);
void				*ft_calloc(size_t nitems, size_t size);
char				*ft_strdup(const char *src);
void				ft_putendl_fd(char *s, int fd);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
char				**ft_split(char const *s, char c);

void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// PRINTF //

# define DECIMAL "0123456789"
# define HEXADECIMAL_MA "0123456789ABCDEF"
# define HEXADECIMAL_MIN "0123456789abcdef"

int					ft_printf(char const *format, ...);
int					ft_print_putchar(char c);
int					ft_print_putstr(const char *str);
int					ft_printf_ptr(void *ptr);
int					ft_printf_hexlong(unsigned long nbr, char *base);
int					ft_checkparam(const char *input, int i, int count,
						va_list pa);

int					ft_print_unsingened(unsigned int num);
int					ft_printf_putnbr(int n);
size_t				ft_strlen2(const char *str);
int					ft_putnbr_base_uns(unsigned int nbr, char *base);
int					ft_print_pa(int i, int count, const char *inp,
						va_list argms);
int					ft_hexpointer(unsigned long pnt);
int					ft_checkbase(char *base);

// GET NEXT LINE //

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

char				*get_next_line(int fd);
char				*ft_save(char *stash);
char				*ft_line(char *stash);
char				*ft_read_and_stash(int fd, char *stash);

#endif
