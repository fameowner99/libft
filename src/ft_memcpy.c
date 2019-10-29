/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:04:49 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 14:13:43 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*res;
	const unsigned char	*src1;

	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	res = dst;
	src1 = src;
	while (n--)
	{
		*res++ = *src1++;
	}
	return (dst);
}
