/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:22:01 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:39:14 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d ", ft_isprint('a'));
	printf("%d ", isprint('a'));

	printf("%d ", ft_isprint(0xff));
	printf("%d ", isprint(0xff));
	
	printf("%d ", ft_isprint(0x0c));
	printf("%d", isprint(0x0c));
}
*/