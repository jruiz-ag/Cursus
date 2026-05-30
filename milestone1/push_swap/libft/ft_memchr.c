/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:17:54 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:17:55 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;

	temp = NULL;
	while (n > 0)
	{
		if (*(unsigned char *)s == (unsigned char)c)
		{
			temp = (char *)s;
			return (temp);
		}
		s++;
		--n;
	}
	return (temp);
}

/*int	main(void)
{
	char	arr[] = "bonjour";
	char	c = 'o';
    size_t  n = 7;
    char    *ft_prueba = ft_memchr(arr, c, n);
    char    *prueba = memchr(arr, c, n);
	printf("El puntero contiene: %s\n", ft_prueba);
	printf("El puntero contiene: %s\n", prueba);
	return (0);
}*/
