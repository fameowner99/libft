/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:12:03 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/10 14:17:45 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	check_flags(char *format, t_flags *flag, size_t i)
{
	if (format[i] == 'l')
	{
		if (format[i + 1] == 'l')
		{
			flag->ll = 1;
			++i;
		}
		else
			flag->l = 1;
	}
	else if (format[i] == 'h')
	{
		if (format[i + 1] == 'h')
		{
			flag->hh = 1;
			++i;
		}
		else
			flag->h = 1;
	}
	else if (format[i] == 'j')
		flag->j = 1;
	else if (format[i] == 'z')
		flag->z = 1;
	return (i);
}

static size_t	read_after_percent(char *format, t_flags *flag,
												size_t i, va_list lst)
{
	while ((format[i] && (find_spec("-+# *0123456789.hlzjt", format[i])
			|| format[i] == '\'')))
	{
		read_after_percent1(format, flag, i);
		if (format[i] >= '1' && format[i] <= '9')
			i = convert_to_int(format, i, &flag->width) - 1;
		else if (format[i] == '.')
		{
			if (format[i + 1] == '*')
			{
				flag->precision = va_arg(lst, int);
				if (format[i + 1])
					++i;
			}
			else
				i = convert_to_int(format, i + 1, &flag->precision) - 1;
		}
		else if (format[i] == '*')
			flag->width = va_arg(lst, int);
		i = check_flags(format, flag, i);
		++i;
	}
	return (i);
}

static char		*check_specifier(char const *format, va_list lst,
														t_flags *flag, size_t i)
{
	char	*tmp;

	if (format[i] == 'i' || format[i] == 'd' ||
			format[i] == 'D')
		tmp = get_int(lst, flag);
	else if (format[i] == 'o' || format[i] == 'O')
		tmp = get_octal(lst, *flag);
	else if (format[i] == 'x' || format[i] == 'X')
		tmp = get_heximal(lst, *flag);
	else if (format[i] == 'c' || format[i] == 'C')
		tmp = get_char(lst, flag);
	else if (format[i] == 's' || format[i] == 'S')
		tmp = get_string(lst, *flag);
	else if (format[i] == 'p')
		tmp = get_pointer(lst, *flag);
	else if (format[i] == 'u' || format[i] == 'U')
		tmp = get_unsigned_int(lst, *flag);
	else if (format[i] == 'b')
		tmp = get_binary(lst, *flag);
	else
	{
		tmp = ft_memalloc(2);
		tmp[0] = format[i];
	}
	return (tmp);
}

static char		*modify_tmp(char *tmp, t_flags *flag)
{
	if (flag->precision > 0 || flag->specifier == 's')
		tmp = change_precision(tmp, *flag);
	if ((((find_spec("oOxX", flag->specifier))
				&& ft_strcmp("0", tmp) && ft_strlen(tmp) > 0)
					&& flag->hash) || flag->specifier == 'p')
		tmp = hash(tmp, flag);
	if (flag->width)
		tmp = change_width(*flag, tmp);
	tmp = add_character_before(tmp, *flag);
	return (tmp);
}

char			*whole_reading(const char *format, va_list lst,
													size_t i, size_t k)
{
	char		*res;
	char		*tmp;
	t_flags		flag;

	res = "\0";
	while (format[i])
	{
		i += read_before_percent((char*)format + i, &res, 0, 0);
		clear_flags(&flag);
		i += read_after_percent((char *)format + i, &flag, 0, lst);
		if (!format[i])
			break ;
		flag.specifier = format[i];
		tmp = check_specifier((char*)format, lst, &flag, i++);
		tmp = modify_tmp(tmp, &flag);
		k = ft_strlen(tmp);
		if (!flag.value && tmp[0] == '\0')
			k = ft_strlen(tmp + 1);
		res = ft_realloc_fixed_size(res, k + g_nbytes, g_nbytes + 1);
		join_tmp(res, tmp, g_nbytes, flag);
		g_nbytes += k;
		if (!flag.value)
			++g_nbytes;
	}
	return (res);
}
