/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:35:39 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/23 14:35:39 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_in_array(int value, int *list, int length)
{
	int	pos;

	pos = 0;
	while (pos < length)
	{
		if (list[pos] == value)
			return (1);
		++pos;
	}
	return (0);
}
