/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:23:22 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:23:24 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*nodo;

	i = 0;
	nodo = lst;
	while (nodo)
	{
		nodo = nodo->next;
		i++;
	}
	return (i);
}

/*int	main(void)
{
	t_list	*prueba;
	t_list	*prueba_2;
	char	c[] = "Hola";
	char	a[] = "Chau";
	int		i;


	prueba = ft_lstnew(c);
	prueba_2 = ft_lstnew(a);
	ft_lstadd_front(&prueba, prueba_2);
	i = ft_lstsize(prueba);
	printf("El content es: %s\n", prueba->content);
	prueba = prueba->next;
	printf("El next es: %s\n", prueba->content);
	printf("El next es: %p\n", prueba->next);
	printf("El size es %d\n", i);
	free(prueba);
	free(prueba_2);
	return(0);
}*/