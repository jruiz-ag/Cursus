/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:03:34 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/26 18:26:10 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	size_t	cont;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	cont = 0;
	while (cont < len)
	{
		f(cont, &s[cont]);
		++cont;
	}
}

/*
#include <stdio.h>
void func(unsigned int idx, char *str)
{
	*str = (*str + idx);
}

int main()
{
	char prueba[] = "Hello world";
	ft_striteri(prueba, func);
	printf("%s", prueba);
}
*/