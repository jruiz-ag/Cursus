/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:26:44 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/03 15:13:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cont_words(const char *s, char c)
{
	size_t	n_words;
	int		flag;
	int		cont;

	cont = 0;
	flag = 0;
	n_words = 0;
	while (s[cont])
	{
		if (flag == 0 && s[cont] != c)
		{
			n_words += 1;
			flag = 1;
		}
		else if (flag == 1 && s[cont] == c)
			flag = 0;
		++cont;
	}
	return (n_words);
}

static char	**free_previous(char **matrix, int index)
{
	--index;
	while (index >= 0)
	{
		free(matrix[index]);
		--index;
	}
	free(matrix);
	return (NULL);
}

static int	find_new_limit(const char *s, char c, int *idx)
{
	char	*aux;
	int		cont;
	int		init_substr;

	if (*idx != 0)
		*idx += 1;
	cont = 0;
	aux = (char *)&(s[*idx]);
	while (aux[cont] && aux[cont] == c)
		++cont;
	init_substr = *idx;
	*idx = *idx + cont;
	while (aux[cont] && aux[cont] != c)
		++cont;
	return (init_substr + cont - 1);
}

char	**ft_split(const char *s, char c)
{
	size_t	n_words;
	char	**sol;
	int		idx;
	int		idx_limit;
	size_t	idx_words;

	if (!s)
		return (NULL);
	n_words = ft_cont_words(s, c);
	sol = ft_calloc((n_words + 1), sizeof(char *));
	if (sol == NULL)
		return (NULL);
	idx = 0;
	idx_words = 0;
	while (idx_words < n_words)
	{
		idx_limit = find_new_limit(s, c, &idx);
		sol[idx_words] = ft_substr(s, idx, idx_limit - idx + 1);
		if (sol[idx_words] == NULL)
			return (free_previous(sol, idx_words));
		++idx_words;
		idx = idx_limit;
	}
	sol[n_words] = NULL;
	return (sol);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	char	**sol;
	int		index;

	if (argc < 3)
		return (-1);

	sol = ft_split("Dos palabras", argv[2][0]);
	index = 0;
	while (sol[index])
	{
		printf("%s\n", sol[index]);
		++index;
	}
}
*/
