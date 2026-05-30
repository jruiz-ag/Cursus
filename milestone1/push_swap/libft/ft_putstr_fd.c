/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:21:58 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:22:00 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd != -1)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

/*#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	c[] = "Aguante Argentina pa";

	fd = open("prueba_txt.txt", O_RDWR);
	if (fd != -1)
	{
		ft_putstr_fd(c, fd);
		printf("El fd es: %i", fd);
		close(fd);
	}
	else
		printf("Fallo la apertura");
	return (0);
}*/
//En open utilizo el flag 'O_RDWR' para tener acceso de lectura y escritura