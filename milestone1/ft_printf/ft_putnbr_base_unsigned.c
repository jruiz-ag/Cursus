/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:25:26 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/12 20:08:37 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int const nbr, char const *base)
{
	int		cont;
	int		long_base;
	long	ctrl;

	cont = 0;
	ctrl = nbr;
	long_base = ft_strlen(base);
	if (ctrl >= long_base)
		cont += ft_putnbr_u(ctrl / long_base, base);
	ctrl %= long_base;
	cont += write(1, &base[ctrl], 1);
	return (cont);
}
