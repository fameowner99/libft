/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 17:13:54 by vmiachko          #+#    #+#             */
/*   Updated: 2018/02/01 17:18:05 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void					*ft_realloc(void *ptr, size_t size)
{
	char					*newptr;
	size_t					oldsize;

	newptr = NULL;
	oldsize = ft_strlen(ptr);
	if (size + oldsize <= oldsize)
		return (ptr);
	newptr = (char *)ft_memalloc(size + oldsize);
	ft_memcpy(newptr, ptr, oldsize);
	if (oldsize > 0)
		free(ptr);
	return (newptr);
}
