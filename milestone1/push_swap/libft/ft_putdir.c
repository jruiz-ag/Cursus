/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 19:54:08 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/20 20:44:22 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_dir(unsigned long const nbr, char const *base)
{
	int				cont;
	unsigned long	long_base;
	unsigned long	ctrl;

	cont = 0;
	ctrl = nbr;
	long_base = (unsigned long)ft_strlen_prnt(base);
	if (ctrl >= long_base)
		cont += ft_putnbr_dir(ctrl / long_base, base);
	ctrl %= long_base;
	cont += write(1, &base[ctrl], 1);
	return (cont);
}

int	ft_putdir(unsigned long const dir)
{
	int	cont;

	if (!dir)
		return (write(1, "(nil)", 5));
	cont = write(1, "0x", 2);
	cont += ft_putnbr_dir(dir, "0123456789abcdef");
	return (cont);
}
