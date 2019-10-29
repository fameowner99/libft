/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_fixed_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:51:42 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/09 11:54:40 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_realloc_fixed_size(void *ptr,
									size_t size, size_t oldsize)
{
	char					*newptr;

	newptr = NULL;
	if (size + oldsize <= oldsize)
		return (ptr);
	newptr = (char *)ft_memalloc(size + oldsize);
	ft_memcpy(newptr, ptr, oldsize);
	if (oldsize > 0)
		free(ptr);
	return (newptr);
}
