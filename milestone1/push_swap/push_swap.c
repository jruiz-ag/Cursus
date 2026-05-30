/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42malaga.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:42:35 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/30 10:31:49 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Revise the first argv to see if its any of the valid flags.
 * @param stack Pointer to the strings of argv.
 * @return -1, 0, 1, 2 or 3 depending on the algorithm selected.
 */
static int	select_flag(char ***argv, int first_arg)
{
	int	flag;

	flag = -1;
	if (ft_strncmp(**argv, "--simple", 9) == 0)
		flag = SIMPLE;
	else if (ft_strncmp(**argv, "--medium", 9) == 0)
		flag = MEDIUM;
	else if (ft_strncmp(**argv, "--complex", 10) == 0)
		flag = COMPLEX;
	else if (ft_strncmp(**argv, "--adaptive", 11) == 0)
		flag = ADAPTATIVE;
	else if ((ft_strncmp(**argv, "--bench", 8) == 0) && first_arg)
		flag = BENCH;
	if (flag != -1)
		++(*argv);
	else
		flag = ADAPTATIVE;
	return (flag);
}

/**
 * @brief Control the disorder_index to choice the correspondent algorithm.
 * @param disorder_index The index of disorder of the stack.
 * @return 0, 1, 2 controlling which algorithm is going to be launch.
 */
static int	select_by_disorder(double disorder_index)
{
	if (disorder_index < 0.2)
		return (SIMPLE);
	else if (disorder_index < 0.5)
		return (MEDIUM);
	else
		return (COMPLEX);
}

/**
 * @brief Depend on the flag given launch any of the three algorithms.
 * @param s_a Pointer to any node of stack a.
 * @param s_b Pointer to any node of stack b.
 * @param flag The flag which is the algorithm selected.
 * @return 0 is all is okey, ERROR in other cases.
 */
static int	algorithm(t_stack **s_a, t_stack **s_b, int flag, t_bench *control)
{
	if (compute_disorder(*s_a) == 0)
		return (0);
	if (flag == SIMPLE)
		insertion_sort(s_a, s_b, control);
	else if (flag == MEDIUM)
		chunk_sort(s_a, s_b, control);
	else if (flag == COMPLEX)
		radix_sort(s_a, s_b, control);
	return (0);
}

/**
 * @brief Reduce number of lines of main.
 * @param argv Pointer to all of the strings given.
 * @param argc Number of strings given
 * @param flag The flag which is the algorithm selected.
 * @param bench The flag to control if the benchmark is used.
 * @return 0 is all is okey, -1 if there is no args.
 */
static int	extract_flag(char ***argv, int argc, int *flag, int *bench)
{
	++(*argv);
	if (argc <= 1)
		return (-1);
	*flag = select_flag(argv, 1);
	*bench = 0;
	if (*flag == BENCH)
	{
		*bench = 1;
		*flag = select_flag(argv, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_bench	control;
	t_stack	*list_a;
	t_stack	*list_b;
	int		bench;
	int		flag;

	if (extract_flag(&argv, argc, &flag, &bench))
		return (0);
	list_a = first_node((const t_stack *)build_list(argv));
	if (!list_a)
		return (error());
	list_b = NULL;
	initialize_bench(&control, compute_disorder(list_a), flag);
	if (flag == ADAPTATIVE)
	{
		if (lst_size(list_a) <= 5)
			small_sort(&list_a, &list_b, &control);
		flag = select_by_disorder(compute_disorder(list_a));
	}
	if (algorithm(&list_a, &list_b, flag, &control) == ERROR)
		free_both(&list_a, &list_b, ERROR);
	if (bench == 1)
		print_bench(&control);
	free_both(&list_a, &list_b, 0);
}
