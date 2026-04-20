/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:50:29 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/20 19:09:15 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cont;

	if (!dest && !src)
		return (0);
	cont = 0;
	while (cont < n)
	{
		((unsigned char *) dest)[cont] = ((unsigned char *) src)[cont];
		++cont;
	}
	return (dest);
}
