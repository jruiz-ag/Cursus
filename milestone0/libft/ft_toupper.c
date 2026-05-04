/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:52:12 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:45:22 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		return (c - 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int main()
{
	printf("%c ", ft_toupper('c'));
	printf("%c\n", toupper('c'));
	
	printf("%c ", ft_toupper('Z'));
	printf("%c\n", toupper('Z'));

	printf("%c ", ft_toupper('?'));
	printf("%c", toupper('?'));

}
*/