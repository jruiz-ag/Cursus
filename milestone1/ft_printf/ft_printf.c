/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:13:53 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/12 20:17:57 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	special_case(char const *str, va_list list)
{
	int	cont;

	cont = 0;
	if (*str == 'c')
		cont += ft_putchar(va_arg(list, int));
	else if (*str == 's')
		cont += ft_putstr(va_arg(list, char *));
	else if (*str == 'p')
		cont += ft_putdir(va_arg(list, unsigned long));
	else if ((*str == 'd') || (*str == 'i'))
		cont += ft_putnbr(va_arg(list, int), "0123456789");
	else if ((*str == 'u'))
		cont += ft_putnbr_u(va_arg(list, unsigned int), "0123456789");
	else if (*str == 'x')
		cont += ft_putnbr_u(va_arg(list, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		cont += ft_putnbr_u(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (*str == '%')
		cont += write(1, "%", 1);
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	va_list		list;
	int			cont;

	if (!str)
		return (-1);
	cont = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			++str;
			cont += special_case(str, list);
		}
		else
			cont += write(1, str, 1);
		++str;
	}
	va_end(list);
	return (cont);
}
