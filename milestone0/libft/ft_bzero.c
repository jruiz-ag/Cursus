/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:42:36 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/23 16:50:15 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char s[10] = "Hola";
	ft_bzero(s, 3);
	printf("%d %d %d %d %d\n", s[0], s[1], s[2], s[3], s[4]);

	char r[10] = "Hola";
	bzero(r, 3);
	printf("%d %d %d %d %d", r[0], r[1], r[2], r[3], r[4]);
}
*/