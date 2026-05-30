/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:29:07 by lupin             #+#    #+#             */
/*   Updated: 2026/05/27 23:06:44 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

t_stack	*last_node(const t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return ((t_stack *)lst);
}

t_stack	*first_node(const t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return ((t_stack *)lst);
}

void	print_list(const t_stack *lst)
{
	if (!lst)
	{
		ft_printf("Empty list\n");
		return ;
	}
	ft_printf("[DBEUG] stack values: \n");
	while (lst)
	{
		ft_printf("%i", lst->value);
		if (lst->next)
			ft_printf(", ");
		lst = lst->next;
	}
	ft_printf("\n");
}

int	is_order(t_stack *stack)
{
	if (!stack)
		return (ERROR);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	pos_of_value(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
