/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:52:45 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/12 19:55:14 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int const nbr, char const *base)
{
	int		cont;
	int		long_base;
	long	ctrl;

	cont = 0;
	ctrl = nbr;
	if (ctrl < 0)
	{
		cont += write(1, "-", 1);
		ctrl *= -1;
	}
	long_base = ft_strlen(base);
	if (ctrl >= long_base)
		cont += ft_putnbr(ctrl / long_base, base);
	ctrl %= long_base;
	cont += write(1, &base[ctrl], 1);
	return (cont);
}
