/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:18:02 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:48:39 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*temp;

	temp = dest;
	if (!dest && !src)
		return (temp);
	while (n > 0)
	{
		*(char *)dest = *(char *)src;
		--n;
		dest++;
		src++;
	}
	return (temp);
}

/*int	main(void)
{
	size_t	n;
	char	src[] = "Argentina";
	char	src_1[] = "Argentina";
	char	dest[5] = "";
	char	dest_1[5] = "";
	char	*pointer;
	char	*pointer_1;

	n = 5;
	//printf("direccion dest = %p\n", dest);
	//printf("direccion dest_1 = %p\n", dest_1);
	pointer = ft_memcpy(src+3, src, n);
	pointer_1 = memcpy(src_1+3, src_1, n);
	//printf("Contenido pointer %s\n", pointer);
	//printf("Contenido pointer_1 %s\n", pointer_1);
	printf("Contenido src %s\n", src);
	printf("Contenido src_1 %s\n", src_1);
	//printf("Contenido dest_1 %s\n", dest_1);
	//printf("direccion ft_memcpy (pointer_2) = %p\n", pointer);
	//printf("direccion memcpy (pointer_3) = %p\n", pointer_1);
}*/