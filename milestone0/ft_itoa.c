/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:22:38 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/26 21:26:57 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cont_digits(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*sol;
	int		sign;
	int		last_digit;

	sign = 0;
	len = cont_digits(n);
	if (n < 0)
		sign = 1;
	sol = ft_calloc(len + sign + 1, sizeof(char));
	if (sol == NULL)
		return (NULL);
	while (len > 0)
	{
		last_digit = n % 10;
		if (last_digit < 0)
			last_digit *= -1;
		sol[len + sign - 1] = '0' + last_digit;
		n /= 10;
		--len;
	}
	if (sign == 1)
		sol[0] = '-';
	return (sol);
}
/*
#include <stdio.h>
int main(){
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s", ft_itoa(-2147483648));
}
*/