/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:08:12 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/25 19:07:15 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (!alst || !del || !*alst)
		return ;
	tmp = *alst;
	while (tmp)
	{
		del((tmp->content), tmp->content_size);
		free(tmp);
		tmp = tmp->next;
	}
	*alst = NULL;
}
