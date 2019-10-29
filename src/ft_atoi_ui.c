/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 02:31:20 by vmiachko          #+#    #+#             */
/*   Updated: 2018/02/20 02:53:58 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			noint(const char *str, size_t *l)
{
	while (str[*l] < '0' || str[*l] > '9')
	{
		if (str[*l] == 10 || str[*l] == 9 || str[*l] == 13 || str[*l] == 11
				|| str[*l] == 12 || str[*l] == 32)
			++(*l);
		else if (str[*l] == '+' || str[*l] == '-')
		{
			++*l;
			if (str[*l] < '0' || str[*l] > '9')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

size_t					ft_atoi_ui(const char *str)
{
	size_t				l;
	size_t				res;

	res = 0;
	l = 0;
	if (!noint(str, &l))
		return (0);
	while (str[l] >= '0' && str[l] <= '9')
	{
		res = res * 10 + str[l] - 48;
		++l;
	}
	return (res);
}
