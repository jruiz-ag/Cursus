/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:30:01 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:40:37 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n)
	{
		((unsigned char *)s)[cont] = c;
		++cont;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char s[10] = "Hola";
	ft_memset(s, 0x12, 3);
	printf("%d %d %d %d %d\n", s[0], s[1], s[2], s[3], s[4]);

	char r[10] = "Hola";
	memset(r, 0x12, 3);
	printf("%d %d %d %d %d", r[0], r[1], r[2], r[3], r[4]);
}
*/