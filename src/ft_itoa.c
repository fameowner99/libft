/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:01:43 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/09 11:54:09 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_string(char *res, intmax_t n)
{
	int		neg;
	int		l;

	l = ft_count_digits(n) - 1;
	neg = 1;
	if (n < 0)
	{
		++l;
		n *= -1;
		neg = -1;
	}
	while (l > -1)
	{
		res[l--] = n % 10 + 48;
		n /= 10;
	}
	if (neg < 0)
		res[0] = '-';
	return (res);
}

char		*ft_itoa(intmax_t n)
{
	char	*res;

	res = NULL;
	res = (char *)ft_memalloc((ft_count_digits(n) + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (n / 10 == -922337203685477580 && n % 10 == -8)
	{
		res = create_string(res, 922337203685477580);
		res[18] = '8';
		res[19] = '\0';
		return (res);
	}
	return (create_string(res, n));
}
