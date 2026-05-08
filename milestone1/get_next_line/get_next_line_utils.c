/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:34:51 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/07 13:48:18 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	cont;

	cont = 0;
	while (str[cont])
	{
		if (str[cont] == c)
			return ((char *)&str[cont]);
		++cont;
	}
	return (NULL);
}

static int	ft_strlen(const char *s1)
{
	int	cont;

	cont = 0;
	if (!s1)
		return (0);
	while (s1[cont])
		++cont;
	return (cont);
}

char	*ft_bzero(char *str, int bytes)
{
	int	idx;

	idx = 0;
	while (idx < bytes)
		str[idx++] = '\0';
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		sum_lens;
	int		s1_len;
	char	*join;
	int		idx;

	sum_lens = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sum_lens + 1);
	if (!join)
		return (NULL);
	ft_bzero(join, sum_lens + 1);
	idx = 0;
	while (s1 && s1[idx])
	{
		join[idx] = s1[idx];
		++idx;
	}
	s1_len = idx;
	while (s2 && (s2[idx - s1_len]))
	{
		join[idx] = s2[idx - s1_len];
		idx++;
	}
	free((char *)s1);
	return (join);
}
