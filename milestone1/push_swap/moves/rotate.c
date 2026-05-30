/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:51:15 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/27 19:00:24 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Rotate the stack. The first node become the last.
 * @param stack Pointer to any node of the stack.
 */
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || (lst_size(*stack) == 1))
		return ;
	first = *stack;
	last = last_node(*stack);
	first->next->prev = NULL;
	*stack = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **stack_a, t_bench *ctr)
{
	rotate(stack_a);
	(ctr->ra)++;
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b, t_bench *ctr)
{
	rotate(stack_b);
	(ctr->rb)++;
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *ctr)
{
	rotate(stack_a);
	rotate(stack_b);
	(ctr->rr)++;
	ft_printf("rr\n");
}
