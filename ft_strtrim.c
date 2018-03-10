/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:36:11 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 14:22:59 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	iterate(char const *s, size_t *j)
{
	while (s[*j] != '\0')
		++*j;
	--*j;
	while (s[*j] == ' ' || s[*j] == '\n' || s[*j] == '\t')
		--*j;
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*res;

	if (s == NULL)
		return (NULL);
	k = 0;
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	if (s[i] == '\0')
	{
		return (ft_strnew(0));
	}
	iterate(s, &j);
	res = (char*)malloc((j - i + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i <= j)
		res[k++] = s[i++];
	res[k] = '\0';
	return (res);
}
