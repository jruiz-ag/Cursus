/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:15:25 by lupin             #+#    #+#             */
/*   Updated: 2026/04/22 19:51:35 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*int	main(void)
{
	char	arr[6] = "Hello";

	printf("strlen(%s) = %lu\n", arr, strlen(arr));
	printf("ft_strlen(%s) = %lu\n", arr, ft_strlen(arr));
}*/