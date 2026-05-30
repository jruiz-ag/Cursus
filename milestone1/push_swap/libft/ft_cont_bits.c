/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cont_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 00:25:44 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/24 00:25:44 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cont_bits(int num)
{
	int	cont;

	if (num == 0)
		return (1);
	cont = 0;
	while (num != 0)
	{
		num /= 2;
		++cont;
	}
	return (cont);
}
