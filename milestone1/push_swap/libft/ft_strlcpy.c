/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:10:27 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:41:59 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	cont;

	cont = 0;
	res = ft_strlen(src);
	if (size == 0)
		return (res);
	while (cont < (size - 1) && src[cont])
	{
		dst[cont] = src[cont];
		++cont;
	}
	dst[cont] = '\0';
	return (res);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char texto[] = "Hola";
	
	char tex1[] = "coso";
	printf("%zu ", ft_strlcpy(tex1, texto, 5));
	printf("%s\n", tex1);
	
	char tex2[] = "coso";
	printf("%zu ", strlcpy(tex2, texto, 5));
	printf("%s", tex2);
}
*/