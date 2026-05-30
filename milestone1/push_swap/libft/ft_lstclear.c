/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:24:02 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:24:03 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		aux = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = aux;
	}
}

/*void	del(void *s)
{
	while (*(char *)s)
	{
		*(char *)s = 0;
		s++;
	}
}

int	main(void)
{
	t_list	*lst;
	t_list	*node_1;
	char	a[] = "Hola";
	char	b[] = "que";
	char	c[] = "tal";
	char	d[] = "?";
	char	e[] = "Bien";

	lst = ft_lstnew(a);
	node_1 = ft_lstnew(b);
	ft_lstadd_back(&lst, node_1);
	node_1 = ft_lstnew(c);
	ft_lstadd_back(&lst, node_1);
	node_1 = ft_lstnew(d);
	ft_lstadd_back(&lst, node_1);
	node_1 = ft_lstnew(e);
	ft_lstadd_back(&lst, node_1);
	ft_lstclear(&lst, del);
	printf("La direccion de la lista  es: %p\n", lst);
	return (0);
}*/