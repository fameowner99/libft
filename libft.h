/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:08:47 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/14 19:48:33 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define ABS(NUM) ((NUM > 0) ? (NUM) : -(NUM))
# include <string.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
char				*ft_itoa(intmax_t n);
void				ft_putnbr(int nb);
void				ft_putstr(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_atoi(const char *str);
void				ft_bzero(void *str, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c,
					size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *str, int c, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(char *str, char *to_find, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(char *str, char *to_find);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_count_digits(intmax_t n);
size_t				ft_count_letters(char const *s, char c);
size_t				ft_count_words(char const *s, char c);
int					*ft_bubble_sort(int *arr, int n);
int					ft_max(int *tab, int length);
int					get_next_line(const int fd, char **line);
void				*ft_realloc(void *ptr, size_t size);
size_t				ft_atoi_ui(const char *str);
char				*decode(int value_of_character);
void				ft_putstr_fixed_size(const char *str, size_t nbytes);
void				*ft_realloc_fixed_size(void *ptr,
									size_t size, size_t oldsize);
void				ft_swap(double *a, double *b);
int					ft_abs(double v);
int					ft_printf(const char *format, ...);
void				**ft_alloc_2d(size_t wrd, size_t str);
int					**ft_alloc_2d_int(size_t wrd, size_t str);
void				ft_free_2d(void **arr);
void				ft_free_2d_int(void **arr, size_t n);
#endif
