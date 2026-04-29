/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:16:13 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:38:26 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d ", ft_isascii('a'));
	printf("%d ", isascii('a'));

	printf("%d ", ft_isascii(0x0c));
	printf("%d ", isascii(0x0c));

	printf("%d ", ft_isascii(128));
	printf("%d ", isascii(128));
	
	printf("%d ", ft_isascii(127));
	printf("%d", isascii(127));
}
*/