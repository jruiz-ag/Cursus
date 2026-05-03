/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:29:22 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/26 18:48:51 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>
int main()
{
	ft_putchar_fd('a', 0);

	int fd = open("eval.md", O_CREAT|O_TRUNC|O_WRONLY, 0666);
	ft_putchar_fd('c', fd);
	close(fd);
}
*/