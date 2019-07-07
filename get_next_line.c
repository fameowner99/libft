/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmiachko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:18:43 by vmiachko          #+#    #+#             */
/*   Updated: 2018/03/26 16:42:26 by vmiachko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list				*check_if_first_mentioned(size_t fd, t_list **t)
{
	t_list					*tmp;

	tmp = *t;
	if (tmp == NULL)
	{
		tmp = ft_lstnew("\0", 1);
		tmp->content_size = fd;
		*t = tmp;
		return (*t);
	}
	while (tmp)
	{
		if (fd == tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(t, tmp);
	return (*t);
}

static int					reading(char *content, char **res,
			t_counters counter, t_list *t)
{
	char					buf[BUFF_SIZE + 1];

	while ((counter.b = read((int)t->content_size, buf, BUFF_SIZE)))
	{
		buf[counter.b] = '\0';
		counter.i = 0;
		while (buf[counter.i])
		{
			if (buf[counter.i] == '\n')
			{
				*res = ft_realloc(*res, counter.i + 1);
				ft_memmove(*res + ft_strlen(*res), buf, counter.i);
				ft_memmove(t->content, (buf + counter.i + 1),
								ft_strlen(buf + counter.i + 1) + 1);
				return (1);
			}
			++counter.i;
		}
		*res = ft_realloc(*res, (size_t)(counter.i + 1));
		ft_memmove(*res + ft_strlen(*res), buf, counter.i + 1);
	}
	content[0] = '\0';
	return (**res == '\0' ? 0 : 1);
}

static int					read_from_file(t_list *t, char **res,
														t_counters counter)
{
	char					*content;

	content = t->content;
	if (content[0] != '\0')
	{
		counter.i = 0;
		while (content[counter.i])
		{
			if (content[counter.i] == '\n')
			{
				*res = ft_realloc(*res, counter.i + 1);
				ft_memmove(*res, content, counter.i + 1);
				res[0][counter.i] = '\0';
				ft_memmove(content, (content + counter.i + 1),
							ft_strlen(content + counter.i) + 1);
				return (1);
			}
			++counter.i;
		}
		*res = ft_realloc(*res, counter.i + 1);
		ft_memmove(*res, content, counter.i + 1);
	}
	return (reading(content, res, counter, t));
}

int							get_next_line(const int fd, char **line)
{
	static t_list	*t = NULL;
	t_list			*tmp;
	t_counters		counter;

	counter.i = 0;
	tmp = t;
	if (fd < 0 || read(fd, tmp, 0) < 0 || !line)
		return (-1);
	tmp = check_if_first_mentioned((size_t)fd, &t);
	*line = "\0";
	return (read_from_file(tmp, line, counter));
}
