/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:30:06 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/09 12:48:34 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**MASK**
**xxxxxx
**110xxxxx 10xxxxxx
**1110xxxx 10xxxxxx 10xxxxxx
**11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

#include "libft.h"
#include "ft_decode.h"

static int	get_mask(int byte)
{
	byte = byte & CUT_FOR_MASK;
	byte = byte | COMMON_MASK;
	return (byte);
}

static char	*use_mask(int value_of_character, char *tmp, int i)
{
	int k;
	int n;

	n = i;
	k = 0;
	while (i)
	{
		tmp[i] = get_mask(value_of_character >> k);
		k += 6;
		--i;
	}
	if (n == 1)
		tmp[i] = value_of_character >> k | 0xC0;
	else if (n == 2)
		tmp[i] = value_of_character >> k | 0xE0;
	else
		tmp[i] = value_of_character >> k | 0xF0;
	return (tmp);
}

char		*decode(int value_of_character)
{
	char	*tmp;

	tmp = ft_memalloc(5);
	if (value_of_character <= 0x7F)
		tmp[0] = (char)value_of_character;
	else if (value_of_character <= 0x7FF)
		tmp = use_mask(value_of_character, tmp, 1);
	else if (value_of_character <= 0xFFFF)
		tmp = use_mask(value_of_character, tmp, 2);
	else if (value_of_character <= 0x10FFFF)
		tmp = use_mask(value_of_character, tmp, 3);
	return (tmp);
}
