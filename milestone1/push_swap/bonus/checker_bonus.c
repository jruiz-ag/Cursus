/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 22:52:31 by lupin             #+#    #+#             */
/*   Updated: 2026/05/30 13:19:33 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	dispatch(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (!move)
		return (ERROR);
	if (ft_strncmp(move, "pa\n", 3) == 0)
		return (pa(stack_a, stack_b), 1);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		return (pb(stack_a, stack_b), 1);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		return (sa(stack_a), 1);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		return (sb(stack_b), 1);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		return (ss(stack_a, stack_b), 1);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		return (ra(stack_a), 1);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		return (rb(stack_b), 1);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		return (rr(stack_a, stack_b), 1);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		return (rra(stack_a), 1);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		return (rrb(stack_b), 1);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		return (rrr(stack_a, stack_b), 1);
	return (ERROR);
}

void	exec_moves(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (dispatch(line, stack_a, stack_b) == ERROR)
		{
			free(line);
			free_both(stack_a, stack_b, ERROR);
		}
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	argv++;
	stack_a = first_node((const t_stack *)build_list(argv));
	stack_b = NULL;
	if (!stack_a)
		return (error());
	exec_moves(&stack_a, &stack_b);
	if (is_order(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_both(&stack_a, &stack_b, 0);
	return (0);
}
