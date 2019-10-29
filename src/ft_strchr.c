/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:38:11 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/07 14:02:56 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			temp = (char*)&s[i];
			return (temp);
		}
		++i;
	}
	if (s[i] == (char)c)
	{
		temp = (char*)&s[i];
		return (temp);
	}
	return (NULL);
}
