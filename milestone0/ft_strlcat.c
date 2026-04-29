/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:12:51 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:41:38 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && (dst_len + i < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char texto[] = "Hola";
	
	char tex1[5] = "coso";
	printf("%zu ", ft_strlcat(tex1, texto, 3));
	printf("%s\n", tex1);
	
	char tex2[5] = "coso";
	printf("%zu ", strlcat(tex2, texto, 3));
	printf("%s", tex2);
}
*/