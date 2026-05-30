/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:24:11 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:24:12 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void	ft_custom(void *s)
{
	*(char *)s = 'A';
}

int	main(void)
{
	t_list	*lst;
	t_list	*node_1;
	char	a[] = "Hola";
	char	b[] = "que";
	char	c[] = "tal";
	char	d[] = "?";

	lst = ft_lstnew(d);
	node_1 = ft_lstnew(c);
	ft_lstadd_front(&lst, node_1);
	node_1 = ft_lstnew(b);
	ft_lstadd_front(&lst, node_1);
	node_1 = ft_lstnew(a);
	ft_lstadd_front(&lst, node_1);
	ft_lstiter(lst, ft_custom);
	printf("La direccion de la lista completa es: %p\n", lst);
	while (lst)
	{
		printf("El contenido de la lista 
		completa es: %s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}*/