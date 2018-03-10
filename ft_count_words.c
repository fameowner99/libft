/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:25:06 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 19:48:34 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_count_words(char const *s, char c)
{
	size_t		counter;
	size_t		i;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			++i;
		if (s[i] != '\0')
			++counter;
		while (s[i] != c && s[i] != '\0')
			++i;
	}
	return (counter);
}
