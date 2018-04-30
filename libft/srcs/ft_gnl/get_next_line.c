/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:21:05 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 16:05:08 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			close_fd(t_fd_lst **fd_contents)
{
	t_fd_lst *to_del;
	t_fd_lst *next;

	to_del = *fd_contents;
	next = (*fd_contents)->next;
	while ((*fd_contents)->next != to_del)
		*fd_contents = (*fd_contents)->next;
	(*fd_contents)->next = next;
	if (to_del->line)
		free(to_del->line);
	if (to_del == *fd_contents)
		*fd_contents = NULL;
	free(to_del);
}

static t_fd_lst		*get_fd_contents(t_fd_lst **fd_contents, const int fd)
{
	t_fd_lst *curr_fd;

	if (!*fd_contents)
	{
		if (!(*fd_contents = (t_fd_lst*)malloc(sizeof(t_fd_lst))))
			return (NULL);
		(*fd_contents)->fd = fd;
		if (!((*fd_contents)->line = ft_strnew(0)))
			return (NULL);
		(*fd_contents)->next = *fd_contents;
	}
	curr_fd = *fd_contents;
	while ((*fd_contents)->fd != fd && (*fd_contents)->next != curr_fd)
		(*fd_contents) = (*fd_contents)->next;
	if ((*fd_contents)->fd != fd)
	{
		if (!((*fd_contents)->next = (t_fd_lst*)malloc(sizeof(t_fd_lst))))
			return (NULL);
		if (!((*fd_contents)->next->line = ft_strnew(0)))
			return (NULL);
		(*fd_contents)->next->fd = fd;
		(*fd_contents)->next->next = curr_fd;
		*fd_contents = (*fd_contents)->next;
	}
	return (*fd_contents);
}

static int			fill(char **line, t_fd_lst *curr_fd)
{
	char	*tmp;
	size_t	lf_pos;

	if (!ft_strchr(curr_fd->line, '\n'))
		ft_putchar('\n');
	lf_pos = ft_strclen(curr_fd->line, LF);
	if (!(*line = ft_strndup(curr_fd->line, lf_pos++)))
		return (-1);
	if (!(tmp = ft_strsub(curr_fd->line, lf_pos, ft_strlen(curr_fd->line))))
		return (-1);
	free(curr_fd->line);
	curr_fd->line = tmp;
	return (1);
}

static int			read_fd(t_fd_lst *curr_fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		read_size;

	ft_bzero(buffer, BUFF_SIZE + 1);
	while ((read_size = read(curr_fd->fd, buffer, BUFF_SIZE)) > 0)
	{
		tmp = ft_strndup(curr_fd->line, ft_strlen(curr_fd->line) + read_size);
		free(curr_fd->line);
		curr_fd->line = NULL;
		if (!tmp)
			return (-1);
		curr_fd->line = tmp;
		buffer[read_size] = '\0';
		ft_strncat(curr_fd->line, buffer, (size_t)read_size);
		if (ft_memchr(buffer, LF, read_size))
			return (fill(line, curr_fd));
	}
	if (ft_strlen(curr_fd->line) > 0 && read_size == 0)
		return (fill(line, curr_fd));
	return (read_size);
}

int					get_next_line(const int fd, char **line)
{
	static t_fd_lst	*fd_contents;
	t_fd_lst		*curr_fd;
	int				read_ret;

	if (fd < 0 || !line || BUFF_SIZE < 0
		|| !(curr_fd = get_fd_contents(&fd_contents, fd)))
		return (-1);
	if (curr_fd->line && (ft_strchr(curr_fd->line, LF)
	|| ft_strchr(curr_fd->line, 4)))
		return (fill(line, curr_fd));
	if ((read_ret = read_fd(curr_fd, line)) <= 0)
		close_fd(&fd_contents);
	return (read_ret);
}
