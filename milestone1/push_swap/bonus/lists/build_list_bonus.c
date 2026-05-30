/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:28:56 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/17 13:28:56 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/**
 * @brief Control that there is no number repeat at least twice.
 * @param lst The stack produced.
 * @return 0 if they are not repeated, 1 if they are.
 */
static int	repeat_args(const t_stack *lst)
{
	t_stack		*i;
	t_stack		*j;

	i = first_node(lst);
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

t_stack	*build_list(char **argv)
{
	t_stack	*lst;

	lst = NULL;
	while (*argv)
	{
		if (get_argv(*argv, &lst) == ERROR)
			return (NULL);
		++argv;
	}
	if (repeat_args(lst))
	{
		free_stack(&lst);
		return (NULL);
	}
	return (lst);
}
