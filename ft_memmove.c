/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:20:11 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 15:39:02 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*res;
	const unsigned char	*src1;

	res = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	if (src < dst)
	{
		while (len--)
		{
			*(res + len) = *(src1 + len);
		}
	}
	else
		ft_memcpy(res, src1, len);
	return (res);
}
