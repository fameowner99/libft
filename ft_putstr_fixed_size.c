/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fixed_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:35:28 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/04 18:40:43 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fixed_size(char const *str, size_t nbytes)
{
	write(STDOUT_FILENO, str, nbytes);
}
