/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:40:31 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/09 16:41:14 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*copy_to_buf(char *res, char *format, size_t i, size_t k)
{
	res = ft_realloc_fixed_size(res, i, g_nbytes);
	if (format[i])
		ft_strncpy(res + g_nbytes, format + k, i - k - 1);
	else
		ft_strncpy(res + g_nbytes, format + k, i - k);
	return (res);
}

static char	*f(char *res, char *format, size_t *i, size_t *k)
{
	++*i;
	res = ft_realloc_fixed_size(res, *i + 1, g_nbytes);
	ft_strncpy(res + g_nbytes, format + *k, *i - *k);
	*k = *i + 1;
	return (res);
}

static void	changer(size_t *amount_of_bytes, size_t *b)
{
	g_nbytes += *amount_of_bytes + 1;
	*amount_of_bytes = 0;
	*b = 1;
}

static void	check(size_t b, size_t *i, size_t *amount_of_bytes)
{
	if (!b)
		++*amount_of_bytes;
	++*i;
}

size_t		read_before_percent(char *format, char **res, size_t i, size_t k)
{
	size_t	amount_of_bytes;
	size_t	b;

	amount_of_bytes = 0;
	while (format[i])
	{
		b = 0;
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				*res = f(*res, format, &i, &k);
				changer(&amount_of_bytes, &b);
			}
			else
			{
				++i;
				break ;
			}
		}
		check(b, &i, &amount_of_bytes);
	}
	*res = copy_to_buf(*res, format, i, k);
	g_nbytes += amount_of_bytes;
	return (i);
}
