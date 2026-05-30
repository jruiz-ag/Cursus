/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 12:54:58 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/28 13:57:46 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	two_sort(t_stack **stack_a, t_bench *ctr)
{
	if (compute_disorder(*stack_a) == 0)
		return ;
	sa(stack_a, ctr);
}

static void	three_sort(t_stack **stack_a, t_bench *ctr)
{
	if (compute_disorder(*stack_a) == 0)
		return ;
	if (((*stack_a)->value) > ((*stack_a)->next)->value)
		sa(stack_a, ctr);
	if (compute_disorder(*stack_a) == 0)
		return ;
	if ((((*stack_a)->value) < (((*stack_a)->next)->next)->value)
		&& (((*stack_a)->next)->value) > (((*stack_a)->next)->next)->value)
	{
		rra(stack_a, ctr);
		sa(stack_a, ctr);
		return ;
	}
	if (((*stack_a)->value) > (((*stack_a)->next)->next)->value)
		rra(stack_a, ctr);
}

static int	min_value(t_stack *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static void	five_sort(t_stack **stack_a, t_stack **stack_b, t_bench *ctr)
{
	int	val;
	int	pos;

	val = min_value(*stack_a);
	pos = pos_of_value(*stack_a, val);
	rotate_stack(stack_a, pos, ctr, 'a');
	pb(stack_a, stack_b, ctr);
	val = min_value(*stack_a);
	pos = pos_of_value(*stack_a, val);
	rotate_stack(stack_a, pos, ctr, 'a');
	pb(stack_a, stack_b, ctr);
	three_sort(stack_a, ctr);
	pa(stack_a, stack_b, ctr);
	pa(stack_a, stack_b, ctr);
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, t_bench *ctr)
{
	if (compute_disorder(*stack_a) == 0)
		return ;
	if (lst_size(*stack_a) == 2)
		two_sort(stack_a, ctr);
	else if (lst_size(*stack_a) == 3)
		three_sort(stack_a, ctr);
	else if (lst_size(*stack_a) == 4)
		insertion_sort(stack_a, stack_b, ctr);
	else if (lst_size(*stack_a) == 5)
		five_sort(stack_a, stack_b, ctr);
}
