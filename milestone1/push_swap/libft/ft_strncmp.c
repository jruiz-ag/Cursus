/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:29:31 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/24 20:04:54 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	if (!s1 || !s2)
		return (0);
	cont = 0;
	while ((cont < n) && s2[cont] && s1[cont])
	{
		if ((unsigned char)s1[cont] != (unsigned char)s2[cont])
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		++cont;
	}
	if (cont < n)
		return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d ", ft_strncmp("Hola que tal", "Hola no", 6));
	printf("%d ", strncmp("Hola que tal", "Hola no", 6));

	printf("%d ", ft_strncmp("Hola que tal", "Hola no", 5));
	printf("%d ", strncmp("Hola que tal", "Hola no", 5));

	printf("%d ", ft_strncmp("Hola que tal", "Hola no", 20));
	printf("%d ", strncmp("Hola que tal", "Hola no", 20));

	printf("%d ", ft_strncmp("ABC", "ABD", 3));
	printf("%d ", strncmp("ABC", "ABD", 3));

	printf("%d ", ft_strncmp("test\200", "test\0", 6));
	printf("%d ", strncmp("test\200", "test\0", 6));
}
*/