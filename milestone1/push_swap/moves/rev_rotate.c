/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:51:15 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/27 19:00:23 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Reverse Rotate the stack. The last node become the first.
 * @param stack Pointer to any node of the stack.
 */
static void	rev_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || (lst_size(*stack) == 1))
		return ;
	first = *stack;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*stack = last;
}

void	rra(t_stack **stack_a, t_bench *ctr)
{
	rev_rotate(stack_a);
	(ctr->rra)++;
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, t_bench *ctr)
{
	rev_rotate(stack_b);
	(ctr->rrb)++;
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *ctr)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	(ctr->rrr)++;
	ft_printf("rrr\n");
}
