/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:58:18 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:44:02 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		cont;

	cont = 0;
	while (s[cont])
	{
		if (s[cont] == c)
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