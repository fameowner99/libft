/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:45:24 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 15:36:44 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t		a;
	size_t		j;
	size_t		count;

	a = 0;
	j = 0;
	count = ft_strlen(to_find);
	if (count == 0)
		return (str);
	while (str[a] != '\0' && a < len)
	{
		while (str[a + j] == to_find[j] && j + a < len)
		{
			if (j == count - 1)
				return (str + a);
			j++;
		}
		j = 0;
		a++;
	}
	return (NULL);
}
