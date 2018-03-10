/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:38:11 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/22 19:56:00 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
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
