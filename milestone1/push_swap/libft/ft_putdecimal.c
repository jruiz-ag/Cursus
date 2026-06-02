/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:44:05 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/29 15:44:05 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdecimal(double num)
{
	int	cont;

	cont = ft_putnbr((const int) num, "0123456789");
	num -= (const int) num;
	num *= 100000;
	while ((((const int)num % 10) == 0) && (num != 0))
		num /= 10;
	if (num != 0)
	{
		cont += write(1, ".", 1);
		cont += ft_putnbr((const int) num, "0123456789");
	}
	return (cont);
}
