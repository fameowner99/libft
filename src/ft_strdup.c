/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:30:59 by vmiachko          #+#    #+#             */
/*   Updated: 2017/11/08 17:59:50 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*x;

	if (!src)
		return (NULL);
	i = 0;
	x = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (x == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		x[i] = src[i];
		++i;
	}
	x[i] = '\0';
	return (x);
}
