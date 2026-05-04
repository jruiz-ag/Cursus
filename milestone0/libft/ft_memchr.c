/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:50:24 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/23 16:50:24 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "Hello, World";
	char *ptr_1 = ft_memchr(str, 'o', 10);
	char *ptr_2 = memchr(str, 'o', 10);

	printf("%s\n", ptr_1);
	printf("%s\n", ptr_2);

	char *ptr_3 = ft_memchr(str, 'o', 2);
	char *ptr_4 = memchr(str, 'o', 2);

	printf("%s\n", ptr_3 ? ptr_3 : "(null)");
	printf("%s\n", ptr_4 ? ptr_4 : "(null)");
}
*/