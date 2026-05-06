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

static size_t	count_words(const char *s, char c)
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
			n_words++;
			flag = 1;
		}
		else if (flag == 1 && s[cont] == c)
			flag = 0;
		cont++;
	}
	return (n_words);
}

static int	skip_delimiters(const char *s, char c, int pos)
{
	while (s[pos] == c)
		pos++;
	return (pos);
}

static int	skip_word(const char *s, char c, int pos)
{
	while (s[pos] && s[pos] != c)
		pos++;
	return (pos);
}

static void	free_all(char **arr, int size)
{
	while (size--)
		free(arr[size]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		pos;
	int		word_index;
	int		start;

	if (!s)
		return (NULL);
	result = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	pos = 0;
	word_index = 0;
	while (s[pos])
	{
		pos = skip_delimiters(s, c, pos);
		if (!s[pos])
			break ;
		start = pos;
		pos = skip_word(s, c, pos);
		result[word_index] = ft_substr(s, start, pos - start);
		if (!result[word_index])
			return (free_all(result, word_index), NULL);
		word_index++;
	}
	return (result);
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