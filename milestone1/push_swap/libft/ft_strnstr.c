/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:18:35 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:57:10 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		ret;
	size_t	little_len;
	size_t	big_len;

	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (*little == '\0')
		return ((char *)big);
	while (len >= little_len && big_len != 0)
	{
		if (*big == *little)
		{
			ret = ft_strncmp(big, little, little_len);
			if (ret == 0)
				return ((char *)big);
		}
		big++;
		--len;
		--big_len;
	}
	return (NULL);
}

/*int	main(void)
{
	char	arr[] = "Argenentina";
	char	arr_1[] = "ent";
	size_t	len = 7;
	char	*ft_prueba = ft_strnstr(arr, arr_1, len);
	char	*prueba = strnstr(arr, arr_1, len);

	printf("ft_strnstr: %s\n", ft_prueba);
	printf("strnstr: %s\n", prueba);
	return (0);
}*/