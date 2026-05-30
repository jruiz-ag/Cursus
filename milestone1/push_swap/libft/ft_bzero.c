/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:15:55 by lupin             #+#    #+#             */
/*   Updated: 2026/04/22 19:55:20 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		ptr[n - 1] = 0;
		--n;
	}
}

/*int	main(void)
{
	size_t	n;
	char	arr[5] = "aaa";
	char	arr_1[5] = "bbb";
	char	*pointer;
	char	*pointer_1;

	n = 1;
	pointer = arr;
	pointer_1 = arr_1;
	printf("Contenido previo de pointer %s\n", pointer);
	printf("Contenido previo pointer_1 %s\n", pointer_1);
	ft_bzero(pointer, n);
	bzero(pointer_1, n);
	printf("Contenido posterior pointer %s\n", pointer);
	printf("Contenido posterior pointer_1 %s\n", pointer_1);
}*/
