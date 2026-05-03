/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:28:38 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/23 17:45:34 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;

	sign = 1;
	nb = 0;
	while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		nb = nb * 10 + (*nptr - '0');
		++nptr;
	}
	return (nb * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *s1 = "   -12312";
	printf("%d ", ft_atoi(s1));	
	printf("%d\n", atoi(s1));
	
	char *s2 = " ++564";
	printf("%d ", ft_atoi(s2));
	printf("%d\n", atoi(s2));

	char *s3 = " +564";
	printf("%d ", ft_atoi(s3));
	printf("%d\n", atoi(s3));

	char *s4 = "-2147483648";
	printf("%d ", ft_atoi(s4));
	printf("%d", atoi(s4));
}
*/