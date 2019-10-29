/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:11:25 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/09 17:28:10 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*width(char *tmp, t_flags flag, char c)
{
	char	*tmp1;
	int		x;
	int		j;
	int		k;

	k = 0;
	tmp1 = ft_memalloc(ft_strlen(tmp) + 1);
	ft_strcpy(tmp1, tmp);
	if (!flag.value)
		--flag.width;
	tmp = ft_realloc(tmp, (size_t)flag.width + 2);
	x = flag.width - (int)ft_strlen(tmp);
	while (k < x)
		tmp[k++] = c;
	j = 0;
	while (tmp1[j])
		tmp[k++] = tmp1[j++];
	free(tmp1);
	return (tmp);
}

char		*change_width(t_flags flag, char *tmp)
{
	int		x;
	char	c;

	if (!flag.minus)
	{
		if (flag.zero && ((find_spec("pdDioOuUxX", flag.specifier)
					&& flag.precision < 0)
								|| ((find_spec("cCsS%", flag.specifier)))
									|| (!find_spec("pdDioOuUxX", flag.specifier)
										&& flag.precision <= 0)))
			c = '0';
		else
			c = ' ';
		tmp = width(tmp, flag, c);
	}
	x = (int)ft_strlen(tmp);
	tmp = ft_realloc(tmp, (size_t)flag.width + 2);
	while (x + !tmp[0] < flag.width)
	{
		tmp[x + !flag.value] = ' ';
		++x;
	}
	return (tmp);
}

char		*change_precision(char *tmp, t_flags flag)
{
	size_t	j;
	char	*tmp1;
	size_t	x;
	size_t	k;

	if (flag.specifier == 's' && !flag.l)
		tmp = precision_string(tmp, flag);
	else if (find_spec("idoxOXUupDb", flag.specifier)
						&& flag.precision > (int)ft_strlen(tmp))
	{
		x = flag.precision - ft_strlen(tmp) + compare_width_precision(flag);
		tmp1 = ft_memalloc(ft_strlen(tmp) + 1);
		ft_strcpy(tmp1, tmp);
		tmp = ft_realloc(tmp, (size_t)flag.precision +
									compare_width_precision(flag));
		k = 0;
		while (k < x)
			tmp[k++] = '0';
		j = 0;
		while (tmp1[j])
			tmp[k++] = tmp1[j++];
		free(tmp1);
	}
	return (tmp);
}

void		join_tmp(char *res, char *tmp, size_t j, t_flags flag)
{
	size_t	k;

	k = 0;
	if (!flag.value && tmp[0] == '\0')
	{
		++j;
		++k;
	}
	while (tmp[k])
	{
		res[j] = tmp[k];
		++k;
		++j;
	}
	free(tmp);
}

char		*precision_string(char *tmp, t_flags flag)
{
	int		curlength;
	char	*tmp1;

	curlength = (int)ft_strlen(tmp);
	if (curlength <= flag.precision || flag.precision == -1)
		return (tmp);
	else
	{
		tmp1 = ft_memalloc((size_t)flag.precision + 1);
		while (flag.precision)
		{
			tmp1[flag.precision - 1] = tmp[flag.precision - 1];
			--flag.precision;
		}
		free(tmp);
		tmp = tmp1;
	}
	return (tmp);
}
