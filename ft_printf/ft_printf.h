/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:01:31 by vmiachko          #+#    #+#             */
/*   Updated: 2018/04/23 17:49:56 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# define RED "\033[0;31m"
# define BRED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BGREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BYELLOW "\033[01;33m"
# define BLUE "\033[0;34m"
# define BBLUE "\033[1;34m"
# define MAGENTA "\033[0;35m"
# define BMAGENTA "\033[1;35m"
# define CYAN "\033[0;36m"
# define BCYAN "\033[1;36m"
# define RESET "\033[0m"

# include "../libft.h"
# include <stdarg.h>
# include <stdlib.h>

size_t			g_nbytes;

typedef struct	s_flags
{
	int			zero;
	int			hash;
	int			plus;
	int			minus;
	int			space;
	int			width;
	int			precision;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	char		specifier;
	int			sign_minus;
	int			value;

}				t_flags;

void			join_tmp(char *res, char *tmp,
										size_t g_nbytes, t_flags flag);

void			clear_flags(t_flags *flag);

size_t			convert_to_int(char *format,
										size_t i, int *flag_equal);

char			*whole_reading(const char *format, va_list lst,
										size_t i, size_t k);

char			*change_width(t_flags flag, char *tmp);

char			*change_precision(char *tmp,
										t_flags flag);

char			*precision_string(char *tmp, t_flags flag);

char			*add_character_before(char *res, t_flags flag);

char			*change_base(size_t number, size_t base);

char			*hash(char *tmp, t_flags *flag);

char			*get_int(va_list lst, t_flags *flag);

char			*get_octal(va_list lst, t_flags flag);

char			*get_heximal(va_list lst, t_flags flag);

char			*get_char(va_list lst, t_flags *flag);

char			*get_string(va_list lst, t_flags flag);

char			*convert_to_hexidecimal(size_t number, char c, int i);

char			*get_pointer(va_list lst, t_flags flag);

char			*get_unsigned_int(va_list lst, t_flags flag);

char			*ft_itoa_ui(size_t n);

int				ft_printf(const char *format, ...);

char			*reverse_string(char *tmp);

int				*precision_long_string(int *arr, t_flags flag);

int				find_spec(const char *str, char c);

int				compare_width_precision(t_flags flag);

char			*get_binary(va_list lst, t_flags flag);

size_t			read_before_percent(char *format,
							char **res, size_t i, size_t k);

void			read_after_percent1(char *format, t_flags *flag, size_t i);

#endif
