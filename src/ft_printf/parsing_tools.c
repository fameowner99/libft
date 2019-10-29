/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:06:53 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/09 14:15:18 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			convert_to_int(char *format,
									size_t i, int *flag_equal)
{
	size_t		j;
	size_t		count;
	char		*tmp;

	tmp = NULL;
	tmp = "\0";
	j = i;
	count = 0;
	while (format[i] >= '0' && format[i] <= '9' && format[i])
	{
		++count;
		++i;
	}
	tmp = ft_realloc(tmp, count + 1);
	ft_strncpy(tmp, (format + j), count);
	tmp[count] = '\0';
	*flag_equal = ft_atoi(tmp);
	free(tmp);
	return (i);
}

void			clear_flags(t_flags *flag)
{
	flag->z = 0;
	flag->j = 0;
	flag->hash = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->precision = -1;
	flag->width = 0;
	flag->zero = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->space = 0;
	flag->specifier = '\0';
	flag->sign_minus = 0;
	flag->value = 1;
}

static int		count_symbols(const int *arr)
{
	int			i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

static int		*copy_array(int *source, int *dest)
{
	int			i;

	i = 0;
	while (source[i])
	{
		dest[i] = source[i];
		++i;
	}
	return (dest);
}

int				*precision_long_string(int *arr, t_flags flag)
{
	int			i;
	int			sum;
	int			*result;
	int			symb;

	symb = count_symbols(arr);
	result = ft_memalloc((size_t)symb * sizeof(int) + 1);
	result = copy_array(arr, result);
	i = 0;
	sum = 0;
	while (i < symb)
	{
		if (arr[i] < 128)
			sum += 1;
		else if (arr[i] < 2048)
			sum += 2;
		else if (arr[i] < 65536)
			sum += 3;
		else
			sum += 4;
		if (sum > flag.precision)
			result[i] = '\0';
		++i;
	}
	return (result);
}
