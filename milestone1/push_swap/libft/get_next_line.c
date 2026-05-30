/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:21:06 by lupin             #+#    #+#             */
/*   Updated: 2026/05/12 20:21:06 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	extract_line(t_info *info)
{
	int		offset;
	char	*aux;

	aux = NULL;
	offset = has_new_line(info->content);
	if (offset == 0 || info->content_size == offset)
	{
		info->ret = join_content("", info->content, info->content_size);
		if (!info->ret)
			return (-1);
		info->content_size = 0;
	}
	else
	{
		info->ret = join_content("", info->content, offset);
		if (!info->ret)
			return (-1);
		info->content_size = info->content_size - offset;
		aux = join_content("", info->content + offset, info->content_size);
		if (!aux)
			return (destroy_memory(&info->ret), -1);
	}
	destroy_memory(&info->content);
	info->content = aux;
	return (0);
}

int	save(t_info *info, char *buffer, int size)
{
	char	*aux;

	aux = NULL;
	if (!info->content)
	{
		info->content = malloc(sizeof(char) * (size + 1));
		if (info->content == NULL)
			return (-1);
		while (size >= 0)
			info->content[size--] = '\0';
	}
	aux = join_content(info->content, buffer, info->content_size);
	if (aux == NULL)
		return (-1);
	destroy_memory(&info->content);
	info->content = aux;
	return (0);
}

int	read_next_line(int fd, t_info *info, char *buffer)
{
	int	read_size;

	read_size = 0;
	while (!has_new_line(info->content))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (-1);
		else if (read_size == 0)
			break ;
		buffer[read_size] = '\0';
		info->content_size += read_size;
		if (save(info, buffer, info->content_size) == -1)
			return (-1);
	}
	if (!info->content)
		return (0);
	return (extract_line(info));
}

char	*get_next_line(int fd)
{
	static t_info	info = {NULL, 0, NULL, -1};
	char			*buffer;
	int				i;
	int				error;

	i = 0;
	info.ret = NULL;
	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (init_gnl(fd, &info, &buffer) == -1)
		return (NULL);
	while (i <= BUFFER_SIZE)
		buffer[i++] = '\0';
	if (!info.content || !has_new_line(info.content))
		error = read_next_line(fd, &info, buffer);
	else
		error = extract_line(&info);
	if (error == -1)
	{
		info.content_size = 0;
		return (destroy_memory(&info.content), destroy_memory(&buffer), NULL);
	}
	destroy_memory(&buffer);
	return (info.ret);
}
