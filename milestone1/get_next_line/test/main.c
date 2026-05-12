/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:07:53 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/11 20:06:44 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("quijote", O_RDONLY);
	//fd = 0;
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
		res = get_next_line(fd);
	}
	//close(fd);
}
