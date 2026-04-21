/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:42:38 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:38:55 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d ", ft_isdigit('a'));
	printf("%d ", isdigit('a'));

	printf("%d ", ft_isdigit('3'));
	printf("%d ", isdigit('3'));
	
	printf("%d ", ft_isdigit(0x0c));
	printf("%d", isdigit(0x0c));
}
*/