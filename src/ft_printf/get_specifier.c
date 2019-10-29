/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:08:18 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/08 20:01:34 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_int(va_list lst, t_flags *flag)
{
	intmax_t	d;

	d = va_arg(lst, intmax_t);
	if (flag->z)
		d = (ssize_t)d;
	else if (flag->j)
		d = (intmax_t)d;
	else if (flag->ll)
		d = (long long)d;
	else if (flag->l || flag->specifier == 'D')
		d = (long)d;
	else if (flag->h)
		d = (short)d;
	else if (flag->hh)
		d = (char)d;
	else
		d = (int)d;
	if (d < 0)
	{
		flag->sign_minus = 1;
		d *= -1;
	}
	if (d == 0 && !flag->precision)
		return (ft_memalloc(1));
	return (ft_itoa(d));
}

char		*get_octal(va_list lst, t_flags flag)
{
	size_t	u;

	u = va_arg(lst, size_t);
	if (flag.z)
		u = (size_t)u;
	else if (flag.j)
		u = (uintmax_t)u;
	else if (flag.ll)
		u = (unsigned long long)u;
	else if (flag.l || flag.specifier == 'O')
		u = (unsigned long)u;
	else if (flag.h)
		u = (unsigned short)u;
	else if (flag.hh)
		u = (unsigned char)u;
	else
		u = (unsigned int)u;
	if (u == 0 && !flag.precision && !flag.hash)
		return (ft_memalloc(1));
	return (change_base(u, 8));
}

char		*get_heximal(va_list lst, t_flags flag)
{
	size_t	u;

	u = va_arg(lst, size_t);
	if (flag.z)
		u = (size_t)u;
	else if (flag.j)
		u = (uintmax_t)u;
	else if (flag.ll)
		u = (unsigned long long)u;
	else if (flag.l || flag.specifier == 'O')
		u = (unsigned long)u;
	else if (flag.h)
		u = (unsigned short)u;
	else if (flag.hh)
		u = (unsigned char)u;
	else
		u = (unsigned int)u;
	if (!flag.precision && u == 0)
		return (ft_memalloc(1));
	return (convert_to_hexidecimal(u, flag.specifier, 0));
}

char		*get_char(va_list lst, t_flags *flag)
{
	int		c;
	char	*tmp;

	c = va_arg(lst, int);
	if (c == 0)
		flag->value = 0;
	if ((flag->specifier == 'c' && flag->l) ||
						flag->specifier == 'C')
		tmp = decode(c);
	else
	{
		tmp = ft_memalloc(2);
		tmp[0] = (char)c;
	}
	return (tmp);
}
