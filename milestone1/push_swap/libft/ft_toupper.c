/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:17:01 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:17:03 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/*int	main(void)
{
	char	c = '%';
	char	ft_c = '%';

	printf("El c es: %c\n", ft_toupper(c));
	printf("El ft_c es: %c\n", ft_toupper(ft_c));
	return (0);
}*/
