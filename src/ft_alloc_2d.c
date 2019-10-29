/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 17:57:47 by vmiachko          #+#    #+#             */
/*   Updated: 2018/05/03 20:42:21 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		**ft_alloc_2d(size_t wrd, size_t str)
{
	void	**buffer;
	size_t	i;

	i = 0;
	buffer = (void **)malloc((wrd + 1) * sizeof(char*));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < wrd)
	{
		buffer[i] = (void*)ft_memalloc((str + 1) * sizeof(char));
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
