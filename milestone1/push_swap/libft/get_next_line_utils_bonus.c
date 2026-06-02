/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 09:34:51 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/20 20:47:10 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr_n(const char *str, int c)
{
	size_t	cont;

	if (!str)
		return (-1);
	cont = 0;
	while (str[cont])
	{
		if (str[cont] == c)
			return (cont);
		++cont;
	}
	return (-1);
}

int	ft_strlen_gnl(const char *s1)
{
	int	cont;

	if (!s1)
		return (0);
	cont = 0;
	while (s1[cont])
		++cont;
	return (cont);
}

char	*ft_strjoin_gnl(char **s1, const char *s2, int max_cpy)
{
	int		sum_lens;
	int		s1_len;
	char	*join;
	int		idx;

	s1_len = ft_strlen_gnl(*s1);
	sum_lens = s1_len + max_cpy;
	join = malloc(sum_lens + 1);
	if (!join)
		return (safe_exit(s1), NULL);
	idx = 0;
	while (*s1 && (*s1)[idx])
	{
		join[idx] = (*s1)[idx];
		++idx;
	}
	while (s2 && (idx - s1_len) < max_cpy)
	{
		join[idx] = s2[idx - s1_len];
		idx++;
	}
	join[idx] = '\0';
	free(*s1);
	return (join);
}
