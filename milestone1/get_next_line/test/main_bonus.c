/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:07:53 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/05/11 16:38:49 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*res1;
	char	*res2;
	char	*res3;

	fd1 = open("prueba1", O_RDONLY);
	fd2 = open("prueba2", O_RDONLY);
	fd3 = open("prueba3", O_RDONLY);
	if (!fd1 || !fd2 || !fd3)
		return (-1);
	res1 = get_next_line(fd1);
	res2 = get_next_line(fd2);
	res3 = get_next_line(fd3);
	while (res1 || res2 || res3)
	{
		if (res1)
			printf("FD1: %s", res1);
		if (res2)
			printf("FD2: %s", res2);
		if (res3)
			printf("FD3: %s", res3);
		free(res1);
		free(res2);
		free(res3);
		res1 = get_next_line(fd1);
		res2 = get_next_line(fd2);
		res3 = get_next_line(fd3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
}
