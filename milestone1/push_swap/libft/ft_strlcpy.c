/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:16:43 by lupin             #+#    #+#             */
/*   Updated: 2026/04/22 19:52:51 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	j = ft_strlen(src);
	if (size == 0)
		return (j);
	if (size > 0)
	{
		while (src[i] != '\0' && (i < size - 1))
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (j);
}

/*int main()
{
	char	destiny_1[] = "hhhhhh";
	char	destiny[] = "hhhhhh";
    char	src_1[] = "abcssbbbb";
	size_t	size_1;
	size_t	size_2;
    
    size_1 = strlcpy(destiny_1, src_1, 5);
    size_2 = ft_strlcpy(destiny, src_1, 5);
    printf("El destino contiene: %s\n", destiny);
	printf("El destino_1 contiene: %s\n", destiny_1);
    return (0);
}*/