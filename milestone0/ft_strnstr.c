/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:07:33 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/23 17:45:16 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_len;
	size_t	little_len;
	size_t	cont;

	cont = 0;
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (big_len > len)
		big_len = len;
	while ((cont + little_len) <= big_len)
	{
		if (big[cont] == little[0])
		{
			if (ft_strncmp(&big[cont], little, little_len) == 0)
				return (&((char *)big)[cont]);
		}
		++cont;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int main()
{
	char *s1 = "Esto es un string largo";
	char *s2 = "es un";
	
	printf("%s\n", ft_strnstr(s1, s2, 10));
	printf("%s\n\n", strnstr(s1, s2, 10));

	printf("%s\n", ft_strnstr(s1, s2, 9));
	printf("%s\n\n", strnstr(s1, s2, 9));


	char *s3 = "Esto es una prueba";
	char *s4 = "algo asi";
	printf("%s\n", ft_strnstr(s3, s4, 30));
	printf("%s\n", strnstr(s3, s4, 30));
}
*/