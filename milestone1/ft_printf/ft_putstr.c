/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:31:50 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/12 19:55:14 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char const *str)
{
	int	cont;

	cont = 0;
	while (str[cont])
		++cont;
	return (cont);
}

int	ft_putstr(char const *str)
{
	int	cont;

	if (!str)
		return (write(1, "(null)", 6));
	cont = write(1, str, ft_strlen(str));
	return (cont);
}
