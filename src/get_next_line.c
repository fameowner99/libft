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

t_list *                    get_remainder(t_list **container, const int fd)
{
    t_list *iterator = *container;

    if (iterator == NULL)
    {
        iterator = ft_lstnew(NULL, fd);
        iterator->content_size = fd;
        *container = iterator;
        return (*container);
    }
    while (iterator)
    {
        if (fd == iterator->content_size)
            return iterator;
        iterator = iterator->next;
    }
    iterator = ft_lstnew(NULL, fd);
    iterator->content_size = fd;
    ft_lstadd(container, iterator);
    return (*container);
}

int                         read_from_file(t_list *container, char **line)
{
    char                    buf[BUFF_SIZE + 1];
    int                     read;
    int                     counter;

    while ((read = ft_read(container->content_size, buf, BUFF_SIZE)))
    {
        buf[read] = '\0';
        counter = 0;
        while (buf[counter])
        {
            if (buf[counter] == '\n')
            {
                *line = ft_realloc(*line, counter + 1);
                ft_memmove(*line + ft_strlen(*line), buf, counter);
                container->content = ft_realloc(container->content, ft_strlen(buf + counter + 1) + 1);
                ft_memmove(container->content, buf + counter + 1, ft_strlen(buf + counter + 1) + 1);
                return (1);
            }
            ++counter;
        }
        *line = ft_realloc(*line, counter + 1);
        ft_memmove(*line + ft_strlen(*line), buf, counter + 1);
    }
    container->content = NULL;
    return (**line == '\0' ? 0 : 1);
}

int                         find_line_break(t_list *container, char **line)
{
    int counter;
    char *content;

    counter = 0;
    if (container->content)
    {
        content = container->content;
        while (content[counter])
        {
            if (content[counter] == '\n')
            {
                *line = ft_realloc(*line, counter + 1);
                ft_memmove(*line, content, counter);
                ft_memmove(content, content + counter + 1, ft_strlen(content + counter + 1) + 1);
                return (1);
            }
            ++counter;
        }
        *line = ft_realloc(*line, counter + 1);
        ft_memmove(*line, content, counter + 1);
        free(content);
        container->content = NULL;
    }
    return (read_from_file(container, line));
}

int							get_next_line(const int fd, char **line)
{
    static t_list *container = NULL;
    t_list *node;

    if (fd < 0 || ft_read(fd, NULL, 0) < 0)
        return (-1);
    node = get_remainder(&container, fd);
    *line = NULL;
    return (find_line_break(node, line));
}
