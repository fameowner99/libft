/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:15:05 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 15:35:40 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = ft_strlen(s);
	while (i + 1)
	{
		if (s[i] == (char)c)
		{
			temp = (char*)&s[i];
			return (temp);
		}
		--i;
	}
	return (NULL);
}
