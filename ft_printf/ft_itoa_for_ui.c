/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_for_ui.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:46:36 by vmiachko          #+#    #+#             */
/*   Updated: 2018/04/23 17:50:50 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_digits_ui(size_t n)
{
	int			i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static char		*create_string(char *res, size_t n)
{
	int			neg;
	int			l;

	l = ft_count_digits_ui(n) - 1;
	neg = 1;
	res[l + 1] = '\0';
	while (l > -1)
	{
		res[l--] = n % 10 + 48;
		n /= 10;
	}
	if (neg < 0)
		res[0] = '-';
	return (res);
}

char			*ft_itoa_ui(size_t n)
{
	char		*res;

	res = (char *)ft_memalloc((ft_count_digits_ui(n) + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	return (create_string(res, n));
}
