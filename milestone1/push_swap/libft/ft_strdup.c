/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:19:49 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:59:33 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s) + 1;
	ptr = ft_calloc(size, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, size);
	return (ptr);
}

/*int	main(void)
{
	char	s[] = "Argentina";
	char	*ft_ptr;
	char	*ptr;

	ft_ptr = ft_strdup(s);
	ptr = strdup(s);
	printf("ft_ptr contiene: %s\n", ft_ptr);
	printf("La longitud de ft_ptr es: %zu\n", ft_strlen(ft_ptr));
	printf("ptr contiene: %s\n", ptr);
	printf("La longitud de ptr es: %zu\n", ft_strlen(ptr));
	return (0);
}*/