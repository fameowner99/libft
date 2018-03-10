/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:53:34 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/26 17:52:28 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			noint(const char *str, int *l, int *neg)
{
	while (str[*l] < '0' || str[*l] > '9')
	{
		if (str[*l] == 10 || str[*l] == 9 || str[*l] == 13 || str[*l] == 11
				|| str[*l] == 12 || str[*l] == 32)
			++(*l);
		else if (str[*l] == '+' || str[*l] == '-')
		{
			if (str[*l] == '-')
				*neg = -1;
			++*l;
			if (str[*l] < '0' || str[*l] > '9')
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int					ft_atoi(const char *str)
{
	int				l;
	int				neg;
	unsigned long	res;

	res = 0;
	neg = 1;
	l = 0;
	if (!noint(str, &l, &neg))
		return (0);
	while (str[l] >= '0' && str[l] <= '9')
	{
		res = res * 10 + str[l] - 48;
		if (res >= 9223372036854775807 && neg == 1)
			return (-1);
		else if (res > 9223372036854775807 && neg == -1)
			return (0);
		++l;
	}
	if (neg == -1)
		res *= -1;
	return (int)(res);
}
