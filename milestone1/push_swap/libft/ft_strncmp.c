/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:17:41 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:17:42 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_aux;
	unsigned char	*s2_aux;

	s1_aux = (unsigned char *)s1;
	s2_aux = (unsigned char *)s2;
	while (n > 0 && *s1_aux && *s2_aux)
	{
		if (*s1_aux != *s2_aux)
			return (*s1_aux - *s2_aux);
		--n;
		s1_aux++;
		s2_aux++;
	}
	if (n != 0)
		return (*s1_aux - *s2_aux);
	return (0);
}

/*int	main(void)
{
	char	s1[] = "Ar";
	char	s2[] = "A";
	size_t n = 2;

	printf("ft_strncmp: %i\n", ft_strncmp(s1, s2, n));
	printf("strncmp: %i\n", strncmp(s1, s2, n));
	return (0);
}*/