/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:23:44 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:23:45 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		node = *lst;
		*lst = ft_lstlast(*lst);
		(*lst)->next = new;
		*lst = node;
	}
}

/*int	main(void)
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
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	free(lst);
	return (0);
}*/
