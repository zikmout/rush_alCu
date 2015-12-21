/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:26:00 by ssicard           #+#    #+#             */
/*   Updated: 2015/12/21 16:48:30 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char				*ft_read_user(void)
{
	char		buf[BUFF_SIZE + 1];
	char		*result;

	result = ft_strdup("\0");
	while ((read(0, buf, BUFF_SIZE) > 0))
	{
		result = ft_strjoin(result, buf);
		if (*buf == '\n')
			break ;
	}
	return (result);
}

static t_list		*ft_free_elem(t_list *first, t_list *last)
{
	last = first;
	first = first->next;
	free(last);
	last = NULL;
	return (first);
}

static t_list		*ft_read_input_file(int fd, t_list *first)
{
	char		buffer[BUFF_SIZE + 1];
	size_t		bytes_read;
	size_t		total_bytes_read;
	t_list		*last;

	total_bytes_read = 0;
	last = first;
	while ((bytes_read = read(fd, buffer, BUFF_SIZE) > 0))
	{
		if (*buffer == '\n')
		{
			if (total_bytes_read > 10000 || total_bytes_read < 1)
				return (0);
			last->next = new_node(total_bytes_read);
			total_bytes_read = 0;
			last = last->next;
		}
		else if (!ft_isdigit(*buffer) || !(*buffer))
			return (0);
		else
			total_bytes_read = (*buffer - 48) + total_bytes_read * 10;
	}
	first = ft_free_elem(first, last);
	return (first);
}

static t_list		*ft_read_stinput(int fd, t_list *first, char *tmp, int tt)
{
	char		buffer[BUFF_SIZE];
	size_t		bytes_read;
	t_list		*last;

	last = first;
	while ((bytes_read = read(fd, buffer, BUFF_SIZE) > 0))
	{
		if ((*buffer == '\n' && *tmp == '\n') || !(*buffer))
			break ;
		if (*buffer == '\n')
		{
			if (tt > 10000 || tt < 1)
				return (0);
			last->next = new_node(tt);
			tt = 0;
			last = last->next;
		}
		else if (!ft_isdigit(*buffer))
			return (0);
		else
			tt = (*buffer - 48) + tt * 10;
		*tmp = *buffer;
	}
	first = ft_free_elem(first, last);
	return (first);
}

int					ft_open(char *name)
{
	int			fd;
	char		tmp[1];
	t_list		*first;
	size_t		tt;

	*tmp = 'A';
	tt = 0;
	first = NULL;
	fd = 0;
	if (!(first = malloc(sizeof(t_list))))
		return (0);
	if (name)
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
			return (0);
		if (!(first = ft_read_input_file(fd, first)))
			return (0);
	}
	else if (!(first = ft_read_stinput(0, first, tmp, tt)))
		return (0);
	ft_game_match(first);
	close(fd);
	return (1);
}
