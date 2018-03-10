/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:43:29 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 15:39:35 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && (*s2 == *s1) && n - 1)
	{
		s1++;
		s2++;
		--n;
	}
	return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
}
