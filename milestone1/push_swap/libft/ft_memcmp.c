/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:18:16 by lupin             #+#    #+#             */
/*   Updated: 2026/05/11 20:34:23 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		--n;
		s1++;
		s2++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[] = "Arg\0e";
	char	s2[] = "Arg\0s";
	size_t n = 5;

	printf("ft_memcmp: %i\n", ft_memcmp(s1, s2, n));
	printf("memcmp: %i\n", memcmp(s1, s2, n));
	return (0);
}*/