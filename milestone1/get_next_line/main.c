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

int	main(void)
{
	int		fd;
	char	*res;
	int		cont;

	fd = open("prueba2", O_RDONLY);
	if (fd < 1)
		return (-1);
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
