/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:58:18 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/21 18:43:40 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cont;

	cont = ft_strlen(s);
	while (cont >= 0)
	{
		if (s[cont] == c)
			return ((char *)&s[cont]);
		--cont;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s\n", ft_strrchr("Mi casa es alta", 'a'));
	printf("%s\n", strrchr("Mi casa es alta", 'a'));

	printf("%s\n", ft_strrchr("Mi casa es alta", 's'));
	printf("%s\n", strrchr("Mi casa es alta", 's'));
	
	printf("%s\n", ft_strrchr("Mi casa es alta", 'f'));
	printf("%s", strrchr("Mi casa es alta", 'f'));
}
*/