/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_another_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:31:50 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/08 19:19:53 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*change_base(size_t number, size_t base)
{
	size_t		i;
	char		*converted_number;

	converted_number = ft_memalloc(40);
	i = 0;
	while (number)
	{
		converted_number[i] = number % base + 48;
		number /= base;
		++i;
	}
	converted_number[i] = '\0';
	if (!ft_strlen(converted_number))
		converted_number[0] = '0';
	return (reverse_string(converted_number));
}

char			*reverse_string(char *tmp)
{
	char		*tmp1;
	int			j;
	int			i;

	j = (int)ft_strlen(tmp) - 1;
	i = 0;
	tmp1 = ft_memalloc((size_t)j + 2);
	while (j > -1)
	{
		tmp1[i] = tmp[j];
		--j;
		++i;
	}
	free(tmp);
	return (tmp1);
}

char			*convert_to_hexidecimal(uintmax_t number, char c, int i)
{
	char		*tmp;
	uintmax_t	rem;
	int			pl;

	tmp = "\0";
	pl = 0;
	if (c == 'x')
		pl = 32;
	if (number == 0)
	{
		tmp = ft_memalloc(2);
		tmp[0] = '0';
	}
	while (number)
	{
		rem = number % 16;
		tmp = ft_realloc(tmp, 2);
		if (rem >= 10 && rem <= 16)
			tmp[i++] = pl + 'A' + rem % 10;
		else
			tmp[i++] = rem + 48;
		number /= 16;
	}
	return (reverse_string(tmp));
}
