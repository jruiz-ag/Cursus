/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:42:35 by lupin             #+#    #+#             */
/*   Updated: 2026/05/13 20:03:15 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(char c, int *count)
{
	if (write(1, &c, 1) == -1)
		*count = -1;
	else
		*count = *count + 1;
}

void	ft_printstr(char *str, int *count)
{
	if (str == NULL)
	{
		ft_printstr("(null)", count);
		return ;
	}
	while (*str)
	{
		ft_printchar(*str, count);
		str++;
	}
}

void	ft_castnbr(long long n, int base, int flag, int *count)
{
	if (n < 0)
	{
		ft_printchar('-', count);
		ft_castnbr(-n, base, flag, count);
	}
	else if (n > base - 1)
	{
		ft_castnbr(n / base, base, flag, count);
		ft_castnbr(n % base, base, flag, count);
	}
	if (n >= 0 && n <= 9)
		ft_printchar(n + '0', count);
	else if (n > 9 && n < 16 && base == 16)
	{
		if (flag == 0)
			ft_printchar(n + 87, count);
		else if (flag == 1)
			ft_printchar(n + 55, count);
	}
}

void	ft_unsigned_castnbr(unsigned long long n, int base, int flag,
			int *count)
{
	if (n > (unsigned long long)base - 1)
	{
		ft_unsigned_castnbr(n / base, base, flag, count);
		ft_unsigned_castnbr(n % base, base, flag, count);
	}
	if (n <= 9)
		ft_printchar(n + '0', count);
	else if (n > 9 && n < 16 && base == 16)
	{
		if (flag == 0)
			ft_printchar(n + 87, count);
		else if (flag == 1)
			ft_printchar(n + 55, count);
	}
}
