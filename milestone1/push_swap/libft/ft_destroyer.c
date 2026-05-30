/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroyer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:26:43 by lupin             #+#    #+#             */
/*   Updated: 2026/05/16 19:26:45 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_destroyer(char **to_destroy)
{
	char	*temp;

	temp = *to_destroy;
	if (!temp)
		return (NULL);
	while (*temp)
	{
		*temp = '\0';
		temp++;
	}
	free(*to_destroy);
	*to_destroy = NULL;
	return (NULL);
}
