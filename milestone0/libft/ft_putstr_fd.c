/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 18:43:43 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/26 20:04:32 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

/*
#include <fcntl.h>
int main()
{
	ft_putstr_fd("Hello everyone", 0);

	int fd = open("eval.md", O_CREAT|O_TRUNC|O_WRONLY, 0666);
	ft_putstr_fd("Into a file", fd);
}
*/