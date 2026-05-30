/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:22:14 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:22:16 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	mod;
	int		div;

	div = n / 10;
	mod = (n % 10) + '0';
	if (fd != -1)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		if (n < 0)
		{
			write(fd, "-", 1);
			ft_putnbr_fd(-n, fd);
		}
		else if (div != 0)
			ft_putnbr_fd(div, fd);
		if (mod >= '0' && mod <= '9')
			write(fd, &mod, 1);
	}
}

/*#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		n = 0;

	fd = open("prueba_txt.txt", O_RDWR);
	if (fd != -1)
	{
		ft_putnbr_fd(n, fd);
		printf("El fd es: %i", fd);
		close(fd);
	}
	else
		printf("Fallo la apertura");
	return (0);
}*/
//En open utilizo el flag 'O_RDWR' para tener acceso de lectura y escritura
