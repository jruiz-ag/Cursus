/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:14:11 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:14:12 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*int	main(void)
{
	char	a;
	char	b;

	a = 'a';
	b = '%';
	printf("isalnum(%c) = %d\n", a, isalnum(a));
	printf("ft_isalnum(%c) = %d\n", a, ft_isalnum(a));
	printf("isalnum(%c) = %d\n", b, isalnum(b));
	printf("ft_isalnum(%c) = %d\n", b, ft_isalnum(b));
}*/
