/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:45:42 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/26 21:27:01 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*sol;
	size_t	cont;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	sol = ft_calloc(len + 1, sizeof(char));
	if (sol == NULL)
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		sol[cont] = f(cont, s[cont]);
		++cont;
	}
	return (sol);
}
/*
#include <stdio.h>
char func(unsigned int idx, char str)
{
	return (str + idx);
}

int main()
{
	char *prueba = "Hello world";
	printf("%s", ft_strmapi(prueba, func));
}
*/