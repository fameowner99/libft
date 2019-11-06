/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:14:02 by vmiachko          #+#    #+#             */
/*   Updated: 2019/11/06 19:21:57 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t ft_write(int fd, const void *buf, size_t nbyte)
{
#ifdef OS_Windows
	return _write(fd, buf, nbyte);
#else
	return write(fd, buf, nbyte);
#endif
}
