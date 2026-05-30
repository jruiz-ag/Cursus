/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:39:06 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/23 12:39:06 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_stack **stack)
{
	int		count;
	t_stack	*actual;
	t_stack	*all_list;

	actual = *stack;
	while (actual)
	{
		count = 0;
		all_list = *stack;
		while (all_list)
		{
			if (actual->value > all_list->value)
				++count;
			all_list = all_list->next;
		}
		actual->index = count;
		actual = actual->next;
	}
}

/**
 * @brief Moves all the points to b, chunk by chunk.
 * @param stack_a A pointer to any node of stack a.
 * @param stack_b A pointer to any node of stack b.
 * @param len_chunk The length of the chunk moved in each iteration.
 */
static void	mv_chunks(t_stack **stack_a, t_stack **stack_b, t_bench *ctr)
{
	int	moved;
	int	limit;
	int	len_chunk;

	len_chunk = ft_sqrt(lst_size(*stack_a));
	limit = len_chunk - 1;
	moved = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= limit)
		{
			pb(stack_a, stack_b, ctr);
			++moved;
			if ((*stack_b)->index < (limit - (len_chunk / 2)))
				rb(stack_b, ctr);
		}
		else
			ra(stack_a, ctr);
		if (moved == limit + 1)
		{
			limit += len_chunk;
		}
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *ctr)
{
	int	pos;

	assign_index(stack_a);
	mv_chunks(stack_a, stack_b, ctr);
	while (*stack_b)
	{
		pos = pos_of_value(*stack_b, max_value(*stack_b));
		rotate_stack(stack_b, pos, ctr, 'b');
		pa(stack_a, stack_b, ctr);
	}
}
