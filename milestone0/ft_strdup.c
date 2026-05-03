/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:24:27 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/26 17:59:17 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*sol;

	size = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	sol = ft_calloc(size + 1, sizeof(char));
	if (sol == NULL)
		return (NULL);
	ft_memmove(sol, s, size);
	sol[size] = '\0';
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

	ft_strdup(NULL);
}
*/