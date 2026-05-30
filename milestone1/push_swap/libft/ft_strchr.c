/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:17:21 by lupin             #+#    #+#             */
/*   Updated: 2026/04/27 22:53:41 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s != (char)c)
		return (NULL);
	return ((char *)s);
}

/*int	main(void)
{
	char	str[] = "Argentina";
	int		c = 'l';

	printf("El puntero de str es: %s\n", ft_strchr(str, c));
	printf("El puntero de str es: %s\n", strchr(str, c));
	return (0);
}*/