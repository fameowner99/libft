/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_2d_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:08:10 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/14 17:14:20 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_alloc_2d_int(size_t wrd, size_t str)
{
	int		**buffer;
	size_t	i;

	i = 0;
	buffer = (int **)malloc((wrd + 1) * sizeof(int*));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < wrd)
	{
		buffer[i] = (int*)ft_memalloc((str + 1) * sizeof(int));
		if (buffer[i] == NULL)
		{
			i = 0;
			while (buffer[i])
				free(buffer[i++]);
			free(buffer);
			return (NULL);
		}
		++i;
	}
	buffer[i] = NULL;
	return (buffer);
}
