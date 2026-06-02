/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:58:18 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/24 20:45:52 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cont;
	size_t	len;

	len = ft_strlen(s);
	cont = 0;
	if ((unsigned char)c == '\0')
		return ((char *)&s[len]);
	while (s[cont])
	{
		if ((unsigned char)s[cont] == (unsigned char)c)
			return ((char *)&s[cont]);
		++cont;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s\n", ft_strchr("Mi casa es alta", 'a'));
	printf("%s\n", strchr("Mi casa es alta", 'a'));

	printf("%s\n", ft_strchr("Mi casa es alta", 'b'));
	printf("%s", strchr("Mi casa es alta", 'b'));
}
*/