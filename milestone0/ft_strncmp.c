/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:29:31 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:43:02 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while ((cont < n) && s2[cont] && s1[cont])
	{
		if (s1[cont] != s2[cont])
			return (s1[cont] - s2[cont]);
		++cont;
	}
	if (cont < n)
		return (s1[cont] - s2[cont]);
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
}
*/