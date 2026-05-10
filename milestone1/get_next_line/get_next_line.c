/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:34:22 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/08 12:58:48 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// In this function we control buffer to be free before exit
static void	safe_exit(char **buffer)
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

	new_read = malloc(BUFFER_SIZE);
	if (!new_read)
	{
		safe_exit(buffer);
		return ;
	}
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
	{
		if (s1)
			free(*s1);
		return (NULL);
	}
	len_s1 = ft_strlen(*s1);
	len_s2 = ft_strlen(s2);
	sol = malloc(len_s1 - len_s2 + 1);
	if (!sol)
		return (NULL);
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
	static char	*buffer = NULL;
	char		*first_part;

	find_newline(&buffer, fd);
	if (!buffer)
		return (NULL);
	first_part = until_newline(buffer);
	buffer = after_newline(&buffer, first_part);
	if (!first_part)
		return (NULL);
	return (first_part);
}
