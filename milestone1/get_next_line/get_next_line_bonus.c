/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:34:22 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/12 16:29:31 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// In this function we control buffer to be free before exit
void	safe_exit(char **buffer)
{
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
}

// Here we find the newline in file with a limit of BUFFER_SIZE
static void	find_newline(char **buffer, int fd)
{
	char	*new_read;
	int		n_bytes;

	new_read = malloc(BUFFER_SIZE + 1);
	if (!new_read)
		return (safe_exit(buffer));
	while (ft_strchr(*buffer, '\n') == -1)
	{
		n_bytes = read(fd, new_read, BUFFER_SIZE);
		if (n_bytes <= 0)
		{
			if (n_bytes == -1)
				safe_exit(buffer);
			free(new_read);
			return ;
		}
		new_read[n_bytes] = '\0';
		*buffer = ft_strjoin(buffer, new_read, n_bytes);
	}
	free(new_read);
}

// This function extract a duplication of the substr until first newline
static char	*until_newline(const char *s)
{
	int		cont;
	char	*sol;

	if (!s || *s == '\0')
		return (NULL);
	cont = 0;
	while (s[cont] && (s[cont] != '\n'))
		++cont;
	if (s[cont] == '\n')
		++cont;
	sol = malloc(cont + 1);
	if (!sol)
		return (NULL);
	cont = 0;
	while (s[cont] && (s[cont] != '\n'))
	{
		sol[cont] = s[cont];
		++cont;
	}
	if (s[cont] == '\n')
		sol[cont++] = '\n';
	sol[cont] = '\0';
	return (sol);
}

// This function extract a duplication of the substr after first newline
static char	*after_newline(char **s1, const char *s2)
{
	int		len_s1;
	int		len_s2;
	int		idx;
	char	*sol;

	if (!s2 || ft_strchr(s2, '\n') == -1)
		return (safe_exit(s1), NULL);
	len_s1 = ft_strlen(*s1);
	len_s2 = ft_strlen(s2);
	sol = malloc(len_s1 - len_s2 + 1);
	if (!sol)
		return (safe_exit(s1), NULL);
	idx = 0;
	while ((len_s2 + idx) < len_s1)
	{
		sol[idx] = (*s1)[idx + len_s2];
		++idx;
	}
	sol[idx] = '\0';
	free(*s1);
	return (sol);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*first_part;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024 || read(fd, 0, 0) == -1)
	{
		if (fd >= 0)
			safe_exit(&buffer[fd]);
		return (NULL);
	}
	find_newline(&buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	first_part = until_newline(buffer[fd]);
	if (!first_part)
		return (safe_exit(&buffer[fd]), NULL);
	buffer[fd] = after_newline(&buffer[fd], first_part);
	return (first_part);
}
