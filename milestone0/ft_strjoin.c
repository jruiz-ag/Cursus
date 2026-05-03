/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:31:00 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/26 21:27:03 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sum_lens;
	size_t	len_s1;
	size_t	len_s2;
	char	*sol;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	sum_lens = len_s1 + len_s2;
	sol = ft_calloc(sum_lens + 1, sizeof(char));
	if (sol == NULL)
		return (NULL);
	ft_memmove(sol, s1, len_s1);
	ft_memmove(&sol[len_s1], s2, len_s2);
	sol[sum_lens] = '\0';
	return (sol);
}
/*
#include <stdio.h>
int main()
{
	char *s1 = "cadena1";
	char *s2 = "cadena2";
	printf("%s\n", ft_strjoin(s1, s2));

	char *s3 = "";
	char *s4 = "No hay cadena inicial";
	printf("%s", ft_strjoin(s3, s4));
}
*/