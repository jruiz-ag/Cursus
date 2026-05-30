/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:17:12 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:17:13 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*int	main(void)
{
	char	c = '0';
	char	ft_c = '0';

	printf("El c es: %c\n", ft_tolower(c));
	printf("El ft_c es: %c\n", ft_tolower(ft_c));
	return (0);
}*/