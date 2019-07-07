/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:52:30 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/09 18:04:46 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*get_pointer(va_list lst, t_flags flag)
{
	intmax_t		u;

	u = va_arg(lst, intmax_t);
	if (u == 0 && !flag.precision)
		return (ft_memalloc(1));
	return (convert_to_hexidecimal((size_t)u, 'x', 0));
}

char				*get_unsigned_int(va_list lst, t_flags flag)
{
	size_t			u;

	u = va_arg(lst, size_t);
	if (flag.z)
		u = (size_t)u;
	else if (flag.j)
		u = (uintmax_t)u;
	else if (flag.ll)
		u = (unsigned long long)u;
	else if (flag.l || flag.specifier == 'U')
		u = (unsigned long)u;
	else if (flag.h)
		u = (unsigned short)u;
	else if (flag.hh)
		u = (unsigned char)u;
	else
		u = (unsigned int)u;
	if (!flag.precision && u == 0)
		return (ft_memalloc(1));
	return (ft_itoa_ui(u));
}

char				*get_binary(va_list lst, t_flags flag)
{
	size_t			u;

	u = va_arg(lst, size_t);
	if (flag.z)
		u = (size_t)u;
	else if (flag.j)
		u = (uintmax_t)u;
	else if (flag.ll)
		u = (unsigned long long)u;
	else if (flag.l)
		u = (unsigned long)u;
	else if (flag.h)
		u = (unsigned short)u;
	else if (flag.hh)
		u = (unsigned char)u;
	else
		u = (unsigned int)u;
	return (change_base(u, 2));
}

static	char		*wide_string(int *arr)
{
	int				i;
	char			*p;
	char			*tmp;
	char			*tmp1;

	tmp = (char*)ft_memalloc(1);
	i = 0;
	while (arr[i])
	{
		p = decode(arr[i]);
		tmp1 = ft_strjoin(tmp, p);
		free(tmp);
		free(p);
		tmp = tmp1;
		++i;
	}
	return (tmp);
}

char				*get_string(va_list lst, t_flags flag)
{
	char			*tmp;
	char			*tmp1;
	int				*arr;

	if (flag.specifier == 's' && !flag.l)
	{
		tmp1 = va_arg(lst, char*);
		if (tmp1 == NULL)
			return (ft_strdup("(null)"));
		tmp = ft_memalloc(ft_strlen(tmp1) + 1);
		ft_strcpy(tmp, tmp1);
		return (tmp);
	}
	arr = va_arg(lst, int*);
	if (flag.precision >= 0)
		arr = precision_long_string(arr, flag);
	if (arr == NULL)
		return (ft_strdup("(null)"));
	tmp = wide_string(arr);
	if (flag.precision >= 0)
		free(arr);
	return (tmp);
}
