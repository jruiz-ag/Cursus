/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:21:22 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:21:23 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*ptr;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	ptr = ft_calloc((s_len + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		ptr[i] = f(i, s[i]);
		++i;
	}
	return (ptr);
}

/*
#include <stdio.h>
#include <stdlib.h>

char custom_function(unsigned int index, char c)
{
	if (index % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	else if (index % 2 != 0 && c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	else
		return (c);
}

int	main(void)
{
	char	s[] = "Argentina";
	char	*ptr;

	ptr = ft_strmapi(s, custom_function);
	printf("ptr contiene: %s\n", ptr);
	free(ptr);
	return (0);
}*/