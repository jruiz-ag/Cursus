/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:05:35 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:40:17 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	cont;
	size_t	idx;

	if (!dest && !src)
		return (0);
	if (dest < src)
	{
		cont = 0;
		while (cont < n)
		{
			((unsigned char *) dest)[cont] = ((unsigned char *) src)[cont];
			++cont;
		}
	}
	else
	{
		cont = n;
		while (cont > 0)
		{
			idx = cont - 1;
			((unsigned char *) dest)[idx] = ((unsigned char *) src)[idx];
			--cont;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char dst1[10] = "Hola";
	char src1[10] = "Vacio?";
	ft_memmove(dst1, src1, 3);
	printf("%d %d %d %d %d\n", dst1[0], dst1[1], dst1[2], dst1[3], dst1[4]);

	char dst2[10] = "Hola";
	char src2[10] = "Vacio?";
	memmove(dst2, src2, 3);
	printf("%d %d %d %d %d\n", dst2[0], dst2[1], dst2[2], dst2[3], dst2[4]);
}
*/