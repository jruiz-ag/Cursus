/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:43:14 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/27 18:56:47 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Select the string which describes the strategy.
 * @param flag The strategy selected.
 * @param disorder_idx The disorder index of the original stack.
 * @return The string which better describe it.
 */
static char	*select_strategy(int flag, double disorder_idx)
{
	if (flag == SIMPLE)
		return ("Simple / O(n²)");
	if (flag == MEDIUM)
		return ("Medium / O(n√n)");
	if (flag == COMPLEX)
		return ("Complex / O(nlog(n))");
	if (disorder_idx < 0.2)
		return ("Adaptative / O(n²)");
	if (disorder_idx < 0.5)
		return ("Adaptative / O(n√n)");
	return ("Adaptative / O(log(n))");
}

void	initialize_bench(t_bench *bench, double disorder_idx, int flag)
{
	bench -> disorder_idx = disorder_idx;
	bench -> strategy = select_strategy(flag, disorder_idx);
	bench -> sa = 0;
	bench -> sb = 0;
	bench -> ss = 0;
	bench -> pa = 0;
	bench -> pb = 0;
	bench -> ra = 0;
	bench -> rb = 0;
	bench -> rr = 0;
	bench -> rra = 0;
	bench -> rrb = 0;
	bench -> rrr = 0;
}

/**
 * @brief Sum the total movements done.
 * @param bench The struct with the whole movements.
 * @return The number of totals movements
 */
static int	sum_ops(t_bench *bench)
{
	int	total;

	total = 0;
	total += bench->sa;
	total += bench->sb;
	total += bench->ss;
	total += bench->pa;
	total += bench->pb;
	total += bench->ra;
	total += bench->rb;
	total += bench->rr;
	total += bench->rra;
	total += bench->rrb;
	total += bench->rrr;
	return (total);
}

/**
 * @brief Print the number of movements.
 * @param bench The struct with the whole movements.
 */
static void	print_movements(t_bench *bench)
{
	ft_putstr_fd("\n[bench] sa:  ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra:  ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(bench->rrr, 2);
}

void	print_bench(t_bench *bench)
{
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd((int)(bench->disorder_idx * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd(((int)(bench->disorder_idx * 10000) % 100), 2);
	ft_putstr_fd("%", 2);
	ft_putstr_fd("\n[bench] strategy:  ", 2);
	ft_putstr_fd(bench->strategy, 2);
	ft_putstr_fd("\n[bench] total_ops:  ", 2);
	ft_putnbr_fd(sum_ops(bench), 2);
	print_movements(bench);
}
