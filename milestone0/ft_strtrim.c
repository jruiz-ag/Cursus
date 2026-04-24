/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:57:07 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/24 20:27:32 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	cont;

	cont = 0;
	while (set[cont])
	{
		if (set[cont] == c)
			return (1);
		++cont;
	}
	return (0);
}

static size_t	ft_strlen_whitout_set(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	return (end - start);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	size_t	cont;
	char	*sol;

	if (!s1 || !set)
		return (NULL);
	cont = 0;
	len = ft_strlen_whitout_set(s1, set);
	sol = malloc(len + 1);
	if (sol == NULL)
		return (NULL);
	while ((is_in_set(s1[cont], set)) && s1[cont])
		++cont;
	ft_memmove(sol, &s1[cont], len);
	sol[len] = '\0';
	return (sol);
}
/*
#include <stdio.h>
int main()
{
	// Recorta delante y detrás
	printf("%s\n", ft_strtrim(" ESTO SOLO SE IMPRIME    :", " :"));

	// Recorta solo delante
	printf("%s\n", ft_strtrim(" ESTO SOLO SE IMPRIME    :", " "));

	// Recorta solo detrás
	printf("%s\n", ft_strtrim(" ESTO SOLO SE IMPRIMEbasura", "asrub"));

	// Deja string vacío
	printf("%s\n", ft_strtrim(" ESTO SOLO", " ESTOL"));

	printf("%s", ft_strtrim("   xxxtripouille", " x"));
}
*/