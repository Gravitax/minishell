/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maboye <maboye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:28:45 by maboye            #+#    #+#             */
/*   Updated: 2019/03/18 19:27:54 by maboye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

# define BUFF_SIZE 4096

typedef struct	s_list
{
	void			*content;
	void			*data;
	size_t			content_size;
	size_t			size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			ft_bubblesort(void **add, int (*f)());

int				ft_intlen(int nb);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_ishexa(int c);
int				ft_islower(int c);
int				ft_isop(int c);
int				ft_isprime(int nb);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);

char			*ft_itoa(int n);

void			ft_lstaddback(t_list **alst, t_list *new);
t_list			*ft_lstaddelem(void *data);
t_list			*ft_lstat(t_list *begin_list, unsigned int nbr);
void			ft_lstdel(t_list **alst);
void			ft_lstdelone(t_list **alst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstmerge(t_list **begin_list1, t_list *begin_list2);
void			ft_lstpushback(t_list **begin_list, void *data);
void			ft_lstpushfront(t_list **begin_list, void *data);
t_list			*ft_lstpushparams(int ac, char **av);
int				ft_lstsize(t_list *source);
void			ft_lstsort(t_list **begin_list, int (*cmp)());

void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);

float			ft_power(int nb, int po);

void			ft_print_hex(int nb);
void			ft_print_tab(char **str);
void			ft_printf(const char *format, ...);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);

int				ft_quicksort(void **add, int start, int size, int (*f)());

char			*ft_readfile(char *file);
void			*ft_realloc(void *ptr, size_t new_size);

float			ft_sqrt(int n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcdup(char *src, char c);
char			*ft_strchr(const char *str, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *src);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strfjoin(const char *s1, const char *s2, int choose);
void			ft_striter(char *s, void (*f)(char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *dest, const char *src, size_t nb);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strndup(const char *s1, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
size_t			ft_strnlen(const char *s, size_t maxlen);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *str, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);

void			ft_swap(void **s1, void **s2);
void			ft_tabfree(void **add);
int				ft_tablen(void **add);
void			ft_tabprint(char **str);
int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_wordcount(const char *str, char c);
int				get_next_line(const int fd, char **line);

#endif
