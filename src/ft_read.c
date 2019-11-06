/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:46:05 by vmiachko          #+#    #+#             */
/*   Updated: 2019/11/06 19:46:09 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	 ft_read(int fd, void *buf, size_t nbyte)
{
#ifdef OS_Windows
	return _read(fd, buf, nbyte);
#else
	return read(fd, buf, nbyte);
#endif
}
