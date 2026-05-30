/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:18:47 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/23 15:18:47 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (ERROR);
}

void	free_both(t_stack **stack_a, t_stack **stack_b, int status)
{
	free_stack(stack_a);
	free_stack(stack_b);
	if (status == ERROR)
		ft_putstr_fd("Error\n", 2);
	exit(status);
}
