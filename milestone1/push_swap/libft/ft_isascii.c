/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:14:33 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:14:36 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 128;
	b = 127;
	printf("isascii(%c) = %d\n", a, isascii(a));
	printf("ft_isasccii(%c) = %d\n", a, ft_isascii(a));
	printf("isascii(%c) = %d\n", b, isascii(b));
	printf("ft_isascii(%c) = %d\n", b, ft_isascii(b));
}*/
