/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:41:36 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/11/19 19:53:23 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

/**
 * @struct e_config
 * @brief Contains the configuration who control the whole project.
*/
typedef struct e_config
{
	int	number_of_coders;
	int	time_to_burnout;
	int	time_to_compile;
	int	time_to_debug;
	int	time_to_refactor;
	int	number_of_compiles_required;
	int	dongle_cooldown;
	int	scheduler;
}	t_config;

/**
 * @brief Control if the input values are valid.
 * @param argv Pointer to the strings of argv.
 * @return pointer to struct t_config with the wholes parameters validated.
 */
t_config	*ft_parser(char **argv);

#endif