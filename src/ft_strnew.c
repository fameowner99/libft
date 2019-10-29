/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:33:09 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/23 15:10:18 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = (char*)malloc(sizeof(char) * size + 1);
	if (buffer == NULL)
		return (NULL);
	while (i <= size)
	{
		buffer[i] = '\0';
		++i;
	}
	return (buffer);
}
