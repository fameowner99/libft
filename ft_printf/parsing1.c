/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 19:52:27 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/10 16:55:29 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*minus_flag(char *tmp, t_flags flag)
{
	char	*tmp1;
	size_t	length;
	int		i;

	length = ft_strlen(tmp);
	tmp1 = ft_memalloc(length + 1);
	ft_strcpy(tmp1, tmp);
	i = 0;
	while (i < flag.width - 1)
	{
		tmp[i + 1] = tmp1[i];
		++i;
	}
	tmp[0] = ' ';
	free(tmp1);
	return (tmp);
}

static char	*skip_spaces(char *tmp, t_flags flag)
{
	int i;

	i = 0;
	while (tmp[i] == ' ' && tmp[i])
		++i;
	if (flag.sign_minus)
		tmp[i - 1] = '-';
	else if (flag.plus)
		tmp[i - 1] = '+';
	else
		tmp[i - 1] = ' ';
	return (tmp);
}

static char	*add_signs(char *tmp, t_flags flag)
{
	int		i;
	char	*tmp1;

	tmp1 = ft_memalloc(ft_strlen(tmp) + 1);
	ft_strcpy(tmp1, tmp);
	tmp = ft_realloc(tmp, 2);
	i = 0;
	while (tmp1[i])
	{
		tmp[i + 1] = tmp1[i];
		++i;
	}
	if (flag.sign_minus)
		tmp[0] = '-';
	else if (flag.plus)
		tmp[0] = '+';
	else
		tmp[0] = ' ';
	free(tmp1);
	return (tmp);
}

char		*add_character_before(char *tmp, t_flags flag)
{
	if ((find_spec("idD", flag.specifier)) &&
				(flag.space || flag.sign_minus || flag.plus))
	{
		if (flag.minus && flag.width >= (int)ft_strlen(tmp))
			tmp = minus_flag(tmp, flag);
		if (tmp[0] != ' ')
		{
			if (ft_strcmp(tmp, "0") && tmp[0] == '0'
						&& (flag.width > flag.precision
								|| compare_width_precision(flag)))
			{
				if (flag.sign_minus)
					tmp[0] = '-';
				else if (flag.plus)
					tmp[0] = '+';
				else
					tmp[0] = ' ';
				return (tmp);
			}
			tmp = add_signs(tmp, flag);
		}
		else
			tmp = skip_spaces(tmp, flag);
	}
	return (tmp);
}
