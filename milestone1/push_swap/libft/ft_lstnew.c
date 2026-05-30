/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:23:01 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:23:03 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = malloc(sizeof(t_list));
	if (nodo == NULL)
		return (NULL);
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}

/*int	main(void)
{
	t_list	*prueba;
	char	c[] = "Hola";

	prueba = ft_lstnew(c);
	printf("El content es: %s\n", prueba->content);
	printf("El next es: %p\n", prueba->next);
	free(prueba);
	return(0);
}*/