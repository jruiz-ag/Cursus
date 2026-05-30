/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:20:16 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:20:17 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	total_size;
	char	*ptr;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	total_size = size_s1 + size_s2 + 1;
	ptr = ft_calloc(total_size, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcat(ptr, s1, total_size);
	ft_strlcat(ptr, s2, total_size);
	return (ptr);
}

/*int	main(void)
{
	char	s1[] = "perrito";
	char	s2[] = " malvado";
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	printf("ptr contiene: %s", ptr);
	return (0);
}*/