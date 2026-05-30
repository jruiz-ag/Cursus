/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:54:37 by lupin             #+#    #+#             */
/*   Updated: 2026/05/25 19:48:00 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_stack	*aux;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!stack)
		return (ERROR);
	while (stack)
	{
		aux = stack->next;
		while (aux)
		{
			total_pairs++;
			if (stack->value > aux->value)
				mistakes++;
			aux = aux->next;
		}
		stack = stack->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
