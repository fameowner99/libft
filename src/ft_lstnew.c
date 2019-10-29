/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:24:11 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/23 17:16:55 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	tmp->content_size = content_size;
	tmp->content = malloc(content_size);
	if (tmp->content == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tmp->next = NULL;
	(ft_memcpy(tmp->content, content, content_size));
	return (tmp);
}
