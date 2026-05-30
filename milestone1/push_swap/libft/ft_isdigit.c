/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:13:58 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:14:00 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int	main(void)
{
	char	a;
	char	b;

	a = 'a';
	b = '0';
	printf("isdigit(%c) = %d\n", a, isdigit(a));
	printf("ft_isdigit(%c) = %d\n", a, ft_isdigit(a));
	printf("isdigit(%c) = %d\n", b, isdigit(b));
	printf("ft_isdigit(%c) = %d\n", b, ft_isdigit(b));
}*/
