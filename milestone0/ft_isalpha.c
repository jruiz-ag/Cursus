/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:42:29 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:37:59 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	else if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d ", ft_isalpha('a'));
	printf("%d ", isalpha('a'));

	printf("%d ", ft_isalpha(0x0c));
	printf("%d ", isalpha(0x0c));

	printf("%d ", ft_isalpha('D'));
	printf("%d ", isalpha('D'));

	printf("%d ", ft_isalpha(127));
	printf("%d", isalpha(127));
}
*/