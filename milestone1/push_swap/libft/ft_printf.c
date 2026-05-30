/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 19:43:25 by lupin             #+#    #+#             */
/*   Updated: 2026/05/13 21:46:50 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	select_format(va_list arg, int type, int *count)
{
	unsigned long long	ptr;

	if (type == 'c')
		ft_printchar(va_arg(arg, int), count);
	else if (type == 's')
		ft_printstr(va_arg(arg, char *), count);
	else if (type == 'i' || type == 'd')
		ft_castnbr(va_arg(arg, int), 10, 0, count);
	else if (type == 'u')
		ft_castnbr(va_arg(arg, unsigned int), 10, 0, count);
	else if (type == 'x')
		ft_castnbr(va_arg(arg, unsigned int), 16, 0, count);
	else if (type == 'X')
		ft_castnbr(va_arg(arg, unsigned int), 16, 1, count);
	else if (type == 'p')
	{
		ptr = va_arg(arg, unsigned long long);
		if (ptr == 0)
			ft_printstr("(nil)", count);
		else
		{
			ft_printstr("0x", count);
			ft_unsigned_castnbr(ptr, 16, 0, count);
		}
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i] && count != -1)
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_printchar(str[i], &count);
			else
				select_format(ap, str[i], &count);
		}
		else
			ft_printchar(str[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
