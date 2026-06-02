/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:49:42 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/26 20:04:03 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
#include <fcntl.h>
int main()
{
	ft_putendl_fd("Hello everyone", 0);

	int fd = open("eval.md", O_CREAT|O_TRUNC|O_WRONLY, 0666);
	ft_putendl_fd("Into a file", fd);
}
*/