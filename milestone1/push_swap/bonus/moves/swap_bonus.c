/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:17:41 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/27 23:49:26 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/**
 * @brief Swap the first two elements of a stack.
 * @param stack Pointer to any node of the stack.
 */
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || (lst_size(*stack) <= 1))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (first->next)
		first->next->prev = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
