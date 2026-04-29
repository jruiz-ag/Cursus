/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:52:46 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/23 17:07:23 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n)
	{
		if (((unsigned char *)s1)[cont] != ((unsigned char *)s2)[cont])
			return (((unsigned char *)s1)[cont] - ((unsigned char *)s2)[cont]);
		++cont;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d ", ft_memcmp("Hola que pasa", "Hola otra cosa", 5));
	printf("%d\n", memcmp("Hola que pasa", "Hola otra cosa", 5));

	printf("%d ", ft_memcmp("Hola que pasa", "Hola otra cosa", 30));
	printf("%d\n", memcmp("Hola que pasa", "Hola otra cosa", 30));

	int array1[] = {1, 2, 3};
	int array2[] = {1, 2, 4};

	printf("%d ", ft_memcmp(array1, array2, 8));
	printf("%d\n", memcmp(array1, array2, 8));

	printf("%d ", ft_memcmp(array1, array2, 12));
	printf("%d\n", memcmp(array1, array2, 12));
}
*/