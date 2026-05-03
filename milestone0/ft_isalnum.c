/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:46:48 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:37:34 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d ", ft_isalnum('a'));
	printf("%d ", isalnum('a'));

	printf("%d ", ft_isalnum(0x0c));
	printf("%d ", isalnum(0x0c));

	printf("%d ", ft_isalnum('D'));
	printf("%d ", isalnum('D'));

	printf("%d ", ft_isalnum('4'));
	printf("%d", isalnum('4'));
}
*/