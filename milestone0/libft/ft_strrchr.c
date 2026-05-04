/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:58:18 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/24 20:13:44 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cont;

	if (!s)
		return (NULL);
	cont = ft_strlen(s);
	while (cont >= 0)
	{
		if ((unsigned char)s[cont] == (unsigned char)c)
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