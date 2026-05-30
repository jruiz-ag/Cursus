/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:20:56 by lupin             #+#    #+#             */
/*   Updated: 2026/04/23 21:00:22 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memory_destroyer(char **splitted, int memory_counter)
{
	int	i;

	i = 0;
	while (i < memory_counter)
		free(splitted[i++]);
	free(splitted);
	return (NULL);
}

static size_t	count_substrings(char *s, int c)
{
	size_t	count;
	int		flag;

	flag = 0;
	count = 0;
	if (*s == '\0')
		return (count);
	if (*s != c)
		count++;
	while (*s)
	{
		if (*s == (char)c)
			flag = 1;
		else if (flag == 1 && *s != (char)c)
		{
			count++;
			flag = 0;
		}
		s++;
	}
	return (count);
}

static int	offset(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		++i;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	*to_split;
	char	**splitted;
	size_t	i;
	size_t	substrings_qty;

	i = 0;
	substrings_qty = count_substrings((char *)s, c);
	to_split = (char *)s;
	splitted = (char **)ft_calloc(substrings_qty + 1, sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	while (i < substrings_qty)
	{
		while (*to_split == c && *to_split != '\0')
			to_split++;
		splitted[i] = ft_substr(to_split, 0, offset(to_split, c));
		if (splitted[i] == NULL)
			return (memory_destroyer(splitted, i));
		to_split = ft_strchr(to_split, c);
		i++;
	}
	return (splitted);
}

/*The ft_substr also can return a NULL, 
because of that it's necessary to repeat the if statement*/
/*
int	main(void)
{
	char	s[] = "oco";
	char	c = 'c';
	char	**splitted;
	int		i;

	i = 0;
	splitted = ft_split(s, c);
	while (splitted[i] != NULL)
	{
		printf("splitted[%d] contiene: %s\n", i, splitted[i]);
		++i;
	}
	return (0);
}*/