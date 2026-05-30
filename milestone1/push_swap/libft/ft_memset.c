/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:15:37 by lupin             #+#    #+#             */
/*   Updated: 2026/04/22 19:52:24 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*temp;

	temp = s;
	while (n > 0)
	{
		*(unsigned char *)s = (unsigned char) c;
		--n;
		s++;
	}
	return (temp);
}
/*
int	main(void)
{
	int		c;
	size_t	len;
	char	arr[10] = "bbbbbb";
	char	*pointer;
	char	*pointer_1;

	c = 65;
	len = 3;
	pointer = arr;
	pointer_1 = ft_memset(pointer, c, len);
	printf("retorno ft_memset (pointer) = %p\n", pointer);
	printf("retorno ft_memset (pointer_1) = %p\n", pointer_1);
	printf("Contenido pointer %s\n", pointer);
	pointer_1 = memset(pointer, c, len);
	printf("retorno memset (pointer_1) = %s\n", pointer);
	printf("retorno memset (pointer_1) = %p\n", pointer_1);
	printf("Contenido pointer %s\n", pointer);
}
*/
