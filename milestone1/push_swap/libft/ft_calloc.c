/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:19:37 by lupin             #+#    #+#             */
/*   Updated: 2026/05/11 20:43:55 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb * size > SIZE_MAX)
		return (NULL);
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

/*
int	main(void)
{
	size_t	nmemb;
	char	*ptr;
	char	*pointer;

	nmemb = 5;
	ptr = NULL;
	ptr = ft_calloc(0, 0);
	printf("La dirección de ptr es: %p\n", ptr);
	free(ptr);
	printf("La dirección de ptr es: %p\n", ptr);
	ptr = ft_calloc(nmemb, sizeof(char));
	ft_memset(ptr, 'a', (nmemb * sizeof(char)));
	printf("ptr contiene: %s\n", ptr);
	printf("La longitud de ptr es: %zu\n", ft_strlen(ptr));
	printf("La dirr de ptr es: %p\n", ptr);
	pointer = calloc(nmemb, sizeof(char));
	ft_memset(pointer, 42, (nmemb * sizeof(char)));
	printf("pointer contiene: %s\n", pointer);
	printf("La longitud de pointer es: %zu\n", ft_strlen(pointer));
	printf("La dirr de pointer es: %p\n", pointer);
	return (0);
}*/