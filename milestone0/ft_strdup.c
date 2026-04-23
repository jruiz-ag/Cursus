/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:24:27 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/23 18:54:07 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	idx;
	char	*sol;

	idx = 0;
	if (s == NULL)
		return (NULL);
	sol = malloc(ft_strlen(s) + 1);
	if (sol == NULL)
		return (NULL);
	while (s[idx])
	{
		sol[idx] = s[idx];
		++idx;
	}
	sol[idx] = '\0';
	return (sol);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *src = "Para copiarlo";
	printf("%p %s\n", src, src);

	char *dst_0 = src;
	printf("%p %s\n", dst_0, dst_0);
	
	char *dst_1 = ft_strdup(src);
	printf("%p %s\n", dst_1, dst_1);

	char *dst_2 = strdup(src);
	printf("%p %s\n", dst_2, dst_2);
}
*/