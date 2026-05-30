/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:17:41 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/27 19:00:25 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sa(t_stack **stack_a, t_bench *ctr)
{
	swap(stack_a);
	(ctr->sa)++;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b, t_bench *ctr)
{
	swap(stack_b);
	(ctr->sb)++;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *ctr)
{
	swap(stack_a);
	swap(stack_b);
	(ctr->ss)++;
	ft_printf("ss\n");
}
