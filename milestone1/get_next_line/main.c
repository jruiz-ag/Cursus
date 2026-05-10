/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:07:53 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/10 14:08:02 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*res;
	int		cont;

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	res = get_next_line(fd);
	while (res)
	{
		if (res)
		{
			printf("%s", res);
			free(res);
		}
		else
			printf("\nNulo");
		++cont;
		res = get_next_line(fd);
	}
	close(fd);
}
