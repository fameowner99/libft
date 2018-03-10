/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:31:10 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/24 17:48:05 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char		*res;
	const unsigned char	*src1;

	res = dst;
	src1 = src;
	while (n > 0)
	{
		*res++ = *src1++;
		if (*(src1 - 1) == (unsigned char)c)
			return (res);
		--n;
	}
	return (NULL);
}
