/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:52:12 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:44:52 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int main()
{
	printf("%c ", ft_tolower('c'));
	printf("%c\n", tolower('c'));

	printf("%c ", ft_tolower('Z'));
	printf("%c\n", tolower('Z'));

	printf("%c ", ft_tolower('?'));
	printf("%c", tolower('?'));
}
*/