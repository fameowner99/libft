/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:28:15 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/10 14:14:11 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			compare_width_precision(t_flags flag)
{
	return (flag.width < flag.precision &&
				flag.sign_minus && flag.width > 0
							&& flag.precision > -1);
}

int			find_spec(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

void		read_after_percent1(char *format, t_flags *flag, size_t i)
{
	if (format[i] == '-')
		flag->minus = 1;
	else if (format[i] == '+')
		flag->plus = 1;
	else if (format[i] == '#')
		flag->hash = 1;
	else if (format[i] == '0')
		flag->zero = 1;
	else if (format[i] == ' ')
		flag->space = 1;
}
