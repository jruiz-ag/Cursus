/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:17:32 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:17:34 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = NULL;
	while (*s)
	{
		if (*s == (char)c)
			temp = (char *)s;
		s++;
	}
	if (*s == (char)c)
		temp = (char *)s;
	return (temp);
}

/*int	main(void)
{
	char	arr[] = "Argentinaghfjhgjh";
	char	c = 'n';

	printf("El puntero contiene: %s\n", ft_strrchr(arr, c));
	printf("El puntero contiene: %s\n", strrchr(arr, c));
	return (0);
}*/
