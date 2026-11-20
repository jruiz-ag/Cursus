/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:20:45 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/11/19 19:46:27 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	show_config(t_config *config)
{
	printf("number_of_coders: %d\n", config->number_of_coders);
	printf("time_to_burnout: %d\n", config->time_to_burnout);
	printf("time_to_compile: %d\n", config->time_to_compile);
	printf("time_to_debug: %d\n", config->time_to_debug);
	printf("time_to_refactor: %d\n", config->time_to_refactor);
	printf("compiles_required: %d\n", config->number_of_compiles_required);
	printf("dongle_cooldown: %d\n", config->dongle_cooldown);
	printf("scheduler: %d\n", config->scheduler);
}

int	error(int type)
{
	if (type == 1)
	{
		printf("Invalid values given");
		return (-1);
	}
	printf("Error the input must be: ./codexion <number_of_coders> ");
	printf("<time_to_burnout> <time_to_compile> <time_to_debug> ");
	printf("<time_to_refactor> <number_of_compiles_required> ");
	printf("<dongle_cooldown> <scheduler>");
	return (-1);
}

int	main(int argc, char **argv)
{
	t_config	*config;

	if (argc != 9)
		return (error(0));
	config = ft_parser(argv);
	if (!config)
		return (error(1));
	show_config(config);
	free(config);
}
