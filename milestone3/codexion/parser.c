/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:47:25 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/11/19 19:47:11 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

/**
 * @brief Validate if there is only digit into a string.
 * @param str Pointer to the string.
 * @return 1 if its made only by digits, 0 in other case.
 */
static int	ft_only_digits(char *str)
{
	while (*str)
	{
		if ((*str < '0') || (*str > '9'))
			return (0);
		++str;
	}
	return (1);
}

/**
 * @brief Transform a given string into the represented number.
 * @param str Pointer to the string.
 * @return int with the equivalent integer.
 */
static int	ft_atoi(char *str)
{
	long	nbr;
	int		cont;
	int		sign;

	nbr = 0;
	sign = 1;
	cont = 0;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	if (!ft_only_digits(str))
		return (-1);
	while (str[cont])
	{
		nbr = nbr * 10 + (str[cont] - '0');
		++cont;
	}
	nbr *= sign;
	if ((cont > 10) || (nbr < -2147483648) || (nbr > 2147483647))
		return (-1);
	return (nbr);
}

/**
 * @brief Assign the argv to the control structure.
 * @param config Direction of the pointer of the structure.
 * @param argv The args given in the input.
 */
static void	ft_construct(t_config **config, char **argv)
{
	(*config)->number_of_coders = ft_atoi(argv[1]);
	(*config)->time_to_burnout = ft_atoi(argv[2]);
	(*config)->time_to_compile = ft_atoi(argv[3]);
	(*config)->time_to_debug = ft_atoi(argv[4]);
	(*config)->time_to_refactor = ft_atoi(argv[5]);
	(*config)->number_of_compiles_required = ft_atoi(argv[6]);
	(*config)->dongle_cooldown = ft_atoi(argv[7]);
	if (!strcmp(argv[8], "fifo"))
		(*config)->scheduler = 0;
	else if (!strcmp(argv[8], "edf"))
		(*config)->scheduler = 1;
	else
		(*config)->scheduler = -1;
}

/**
 * @brief Assign the argv to the control structure.
 * @param config Direction of the pointer of the structure.
 * @param return 1 in the case of being valid, 0 in other case.
 */
static int	ft_is_valid(t_config *config)
{
	if (config->number_of_coders < 1)
		return (0);
	if (config->time_to_burnout < 1)
		return (0);
	if (config->time_to_compile < 1)
		return (0);
	if (config->time_to_debug < 1)
		return (0);
	if (config->time_to_refactor < 1)
		return (0);
	if (config->number_of_compiles_required < 1)
		return (0);
	if (config->dongle_cooldown < 1)
		return (0);
	if (config->scheduler == -1)
		return (0);
	return (1);
}

t_config	*ft_parser(char **argv)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	ft_construct(&config, argv);
	if (!ft_is_valid(config))
	{
		free(config);
		return (NULL);
	}
	return (config);
}
