/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:52:50 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/24 17:48:54 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*buffer;

	buffer = (void*)malloc(size);
	if (buffer == NULL)
		return (NULL);
	ft_memset(buffer, 0, size);
	return (buffer);
}
