/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:22:46 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:42:41 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (s[cont])
		++cont;
	return (cont);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s[11] = "Poco menos";

	printf("%zu ", ft_strlen(s));
	printf("%zu ", strlen(s));
	
	printf("%zu ", ft_strlen("Hola que pasa"));
	printf("%zu ", strlen("Hola que pasa"));
}
*/