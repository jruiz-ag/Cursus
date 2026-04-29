/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:50:29 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/27 18:47:41 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cont;

	if (!dest && !src)
		return (NULL);
	cont = 0;
	while (cont < n)
	{
		((unsigned char *) dest)[cont] = ((unsigned char *) src)[cont];
		++cont;
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
	ft_memcpy(dst1, src1, 3);
	printf("%d %d %d %d %d\n", dst1[0], dst1[1], dst1[2], dst1[3], dst1[4]);

	char dst2[10] = "Hola";
	char src2[10] = "Vacio?";
	memcpy(dst2, src2, 3);
	printf("%d %d %d %d %d\n", dst2[0], dst2[1], dst2[2], dst2[3], dst2[4]);

	char dst3[4] = "ABCD";
	ft_memcpy(&dst3[1], dst3, 2);
	printf("%s", dst3);

	ft_memcpy((void *)0, (void *)NULL, 3);
}
*/