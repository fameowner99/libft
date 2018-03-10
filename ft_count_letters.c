/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:23:57 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 20:26:50 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_count_letters(char const *s, char c)
{
	size_t		counter;
	size_t		i;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			++counter;
		++i;
	}
	return (counter);
}
