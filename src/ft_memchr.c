/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:46:58 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/24 20:52:20 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src1;

	src1 = s;
	while (n > 0)
	{
		if (*src1++ == (char)c)
			return ((void *)(src1 - 1));
		--n;
	}
	return (NULL);
}
