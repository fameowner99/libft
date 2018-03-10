/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:39:07 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/23 15:19:28 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	res = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}
