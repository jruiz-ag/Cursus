/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:25:13 by lupin             #+#    #+#             */
/*   Updated: 2026/05/16 19:25:15 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_s1(char *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	total_size;
	char	*ptr;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	total_size = size_s1 + size_s2 + 1;
	ptr = ft_calloc(total_size, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcat(ptr, s1, total_size);
	ft_strlcat(ptr, s2, total_size);
	ft_destroyer(&s1);
	s1 = NULL;
	return (ptr);
}
