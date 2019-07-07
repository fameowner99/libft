/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:15:01 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/26 18:53:28 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		**fill_array(char const *s, char **res, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
			++i;
		while (s[i] != c && s[i] != '\0')
		{
			res[j][k] = s[i];
			++i;
			++k;
			if (s[i] == c || s[i] == '\0')
			{
				res[j][k] = '\0';
				++j;
			}
		}
	}
	res[j] = NULL;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		wrd;

	res = NULL;
	if (s == NULL)
		return (res);
	i = 0;
	wrd = ft_count_words(s, c);
	res = (char**)malloc((wrd + 2) * sizeof(char*));
	if (res == NULL)
		return (NULL);
	while (i < wrd)
	{
		res[i] = (char*)malloc((ft_count_letters(s, c) + 1) * sizeof(char));
		if (res[i] == NULL)
		{
			i = 0;
			while (res[i])
				free(res[i++]);
			return (NULL);
		}
		++i;
	}
	return (fill_array(s, res, c));
}
