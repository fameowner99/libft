/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:10:40 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 16:58:05 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	del(t_list *res, t_list *tmp)
{
	while (res)
	{
		tmp = res->next;
		free(res);
		res = NULL;
		res = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;

	res = NULL;
	tmp = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	res = f(lst);
	if (res == NULL)
		return (NULL);
	tmp = res;
	lst = lst->next;
	while (lst)
	{
		tmp->next = f(lst);
		if (tmp == NULL)
			del(res, tmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (res);
}
