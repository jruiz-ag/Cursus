/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:19:26 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/30 11:54:28 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/**
 * @brief Control there are only number in the string.
 * @param str The string which contains the numbers.
 * @return 0 if they are not only numbers, 1 if they are.
 */
static int	only_digits(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit((int)*str))
			return (0);
		++str;
	}
	return (1);
}

/**
 * @brief Control there are only valid strings, according to traditional atoi.
 * @param str The string which contains the number and maybe simbols.
 * @return 0 if they are not valid, 1 if they are.
 */
static int	is_valid(const char *str)
{
	long	control;
	int		sign;

	sign = 1;
	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str == '0' && *(str + 1) != '\0')
		++str;
	if (!only_digits(str) || (ft_strlen(str) > 10) || ft_strlen(str) < 1)
		return (0);
	control = 0;
	while (*str)
		control = control * 10 + (*(str++) - '0');
	control *= sign;
	if ((control < INT_MIN) || (control > INT_MAX))
		return (0);
	return (1);
}

/**
 * @brief Evaluate if the argvs given are valids.
 * @param argv Array of strings with all the args.
 * @return 0 in case of error, 1 if they are valid.
 */
static int	valid_args(char **argv)
{
	while (*argv)
	{
		if (!is_valid(*argv))
			return (0);
		++argv;
	}
	return (1);
}

/**
 * @brief Prepare the safe exit when there is an error creating the stack.
 * @param str_split Array of strings after the split.
 * @param lst The stack which have been built until this moment.
 * @return ERROR cause have been any problem.
 */
static int	free_split_stack(char ***str_split, t_stack **lst)
{
	ft_split_destroyer(str_split);
	free_stack(lst);
	return (ERROR);
}

int	get_argv(char *argv, t_stack **lst)
{
	t_stack	*new;
	char	**str_split;
	char	**aux;

	str_split = ft_split(argv, ' ');
	if (!str_split || !*str_split)
	{
		free_split_stack(&str_split, lst);
		return (ERROR);
	}
	if (!valid_args(str_split))
		return (free_split_stack(&str_split, lst));
	aux = str_split;
	while (*aux)
	{
		new = new_node(ft_atoi(*aux));
		if (!new)
			return (free_split_stack(&str_split, lst));
		++aux;
		add_node_back(lst, new);
	}
	ft_split_destroyer(&str_split);
	return (0);
}
