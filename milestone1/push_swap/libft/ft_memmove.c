/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:16:30 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:51:03 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst_char;
	char	*src_char;

	dst_char = (char *)dest;
	src_char = (char *)src;
	if (dst_char > src_char && dst_char != NULL && src_char != NULL)
	{
		while (n > 0)
		{
			dst_char[n - 1] = src_char[n - 1];
			--n;
		}
	}
	else
		ft_memcpy(dst_char, src_char, n);
	return (dst_char);
}

/*int	main(void)
{
	char	src[] = "Argentina";
	char	src_1[] = "Argentina";
	char	src_2[] = "Argentina";
	char	*prueba_ft;
	char	*prueba;
	char	*prueba_memcpy;

	prueba_ft = ft_memmove(src+3, src, 5);
	printf("El puntero de prueba_ft contiene: %s\n", prueba_ft);
	printf("El src contiene: %s\n", src);
	prueba = memmove(src_1+3, src_1, 5);
	prueba_memcpy = memcpy(src_2+3, src_2, 5);
	printf("El puntero de prueba contiene: %s\n", prueba);
	printf("El src_1 contiene: %s\n", src_1);
	printf("El puntero de prueba_memcpy contiene: %s\n", prueba_memcpy);
	printf("El src_2 contiene: %s\n", src_2);
	return (0);
}*/
