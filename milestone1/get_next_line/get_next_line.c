/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:34:22 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/07 13:38:20 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*until_newline(char *buffer, int fd)
{
	char	*new_read;
	int		n_bytes;

	new_read = malloc(BUFFER_SIZE);
	if (!new_read)
		return (NULL);
	ft_bzero(new_read, BUFFER_SIZE);
	while (!buffer || !ft_strchr(buffer, '\n'))
	{
		n_bytes = read(fd, new_read, BUFFER_SIZE);
		if (n_bytes == 0)
		{
			free(new_read);
			return (buffer);
		}
		buffer = ft_strjoin(buffer, new_read);
	}
	write(1, "Encontre jejeje", 15);
	free(new_read);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;

	buffer = until_newline(buffer, fd);
	return (buffer);
}
