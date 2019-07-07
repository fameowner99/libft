/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:14:34 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/10 14:52:27 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list	lst;
	char	*res;

	g_nbytes = 0;
	va_start(lst, format);
	res = whole_reading(format, lst, 0, 0);
	ft_putstr_fixed_size(res, g_nbytes);
	if (g_nbytes > 0)
		free(res);
	va_end(lst);
	return ((int)g_nbytes);
}
