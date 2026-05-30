/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:01:58 by lupin             #+#    #+#             */
/*   Updated: 2026/05/12 21:24:05 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*destroy_memory(char **memory)
{
	char	*aux;

	if (!*memory)
		return (NULL);
	aux = *memory;
	while (*aux)
		*aux++ = '\0';
	free(*memory);
	*memory = NULL;
	return (*memory);
}

char	*join_content(char *s1, char *s2, int size)
{
	char	*temp;
	char	*aux;

	temp = NULL;
	if (!s1 || !s2)
		return (NULL);
	temp = malloc(size + 1);
	if (temp == NULL)
		return (NULL);
	temp[size] = '\0';
	aux = temp;
	while (*s1 && size-- > 0)
		*temp++ = *s1++;
	while (*s2 && size-- > 0)
		*temp++ = *s2++;
	return (aux);
}

int	has_new_line(char *content)
{
	int	offset;

	offset = 0;
	if (!content)
		return (0);
	while (content[offset])
	{
		if (content[offset++] == '\n')
			return (offset);
	}
	return (0);
}

int	init_gnl(int fd, t_info *info, char **buffer)
{
	if (info->fd != fd)
	{
		destroy_memory(&info->content);
		info->content_size = 0;
		info->fd = fd;
	}
	*buffer = malloc(BUFFER_SIZE + 1);
	if (!*buffer)
	{
		destroy_memory(&info->content);
		info->content_size = 0;
		return (-1);
	}
	return (0);
}
