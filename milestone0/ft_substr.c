/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:12:39 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/23 19:38:38 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sol;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sol = malloc(len + 1);
	if (sol == NULL)
		return (NULL);
	ft_memcpy(sol, &s[start], len);
	sol[len] = '\0';
	return (sol);
}
/*
#include <stdio.h>
int main()
{
	char *str = "Sirve de referencia";
	printf("%p %s\n", str, str);

	char *dst_0;
	dst_0 = ft_substr(str, 2, 5);
	printf("%p %s\n", dst_0, dst_0);

	char *dst_1;
	dst_1 = ft_substr(str, 100, 1);
	printf("%p %s", dst_1, dst_1);
}
*/