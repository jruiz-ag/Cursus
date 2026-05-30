/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:13:43 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:13:44 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 'a';
	b = '0';
	printf("isalpha(%c) = %d\n", a, isalpha(a));
	printf("ft_isalpha(%c) = %d\n", a, ft_isalpha(a));
	printf("isalpha(%c) = %d\n", b, isalpha(b));
	printf("ft_isalpha(%c) = %d\n", b, ft_isalpha(b));
}*/
