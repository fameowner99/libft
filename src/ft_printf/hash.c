/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:34:12 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/09 11:48:39 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hash_for_o(char *tmp, char *tmp1)
{
	int i;

	i = 0;
	while (tmp1[i])
	{
		tmp[i + 1] = tmp1[i];
		++i;
	}
	tmp[0] = '0';
	return (tmp);
}

static char	*hash_for_x(char *tmp, char *tmp1, t_flags flag)
{
	size_t	i;

	i = 0;
	while (tmp1[i])
	{
		tmp[i + 2] = tmp1[i];
		++i;
	}
	tmp[0] = '0';
	if (flag.specifier == 'x' || flag.specifier == 'p')
		tmp[1] = 'x';
	else
		tmp[1] = 'X';
	return (tmp);
}

char		*hash(char *tmp, t_flags *flag)
{
	char	*tmp1;

	tmp = ft_realloc(tmp, 3);
	tmp1 = ft_memalloc(ft_strlen(tmp) + 1);
	ft_strcpy(tmp1, tmp);
	if ((flag->specifier == 'o' || flag->specifier == 'O')
			&& (int)ft_strlen(tmp) > flag->precision)
		tmp = hash_for_o(tmp, tmp1);
	else if (find_spec("xXp", flag->specifier))
	{
		if (!flag->minus && flag->zero && flag->precision == -1
								&& flag->width >= (int)ft_strlen(tmp) + 3)
		{
			tmp = change_width(*flag, tmp);
			flag->width = 0;
			if (flag->specifier == 'x' || flag->specifier == 'p')
				tmp[1] = 'x';
			else
				tmp[1] = 'X';
		}
		else
			tmp = hash_for_x(tmp, tmp1, *flag);
	}
	free(tmp1);
	return (tmp);
}
