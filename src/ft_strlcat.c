/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:23:02 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 13:54:59 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t srcsize;
	size_t stringsize;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	srcsize = ft_strlen(src);
	if (dst == NULL && dstsize == 0 && src != NULL)
		return (srcsize);
	stringsize = ft_strlen(dst);
	if (dstsize <= stringsize)
		return (srcsize + dstsize);
	while (dst[i] != '\0')
		++i;
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		++j;
	}
	dst[i] = '\0';
	return (srcsize + stringsize);
}
