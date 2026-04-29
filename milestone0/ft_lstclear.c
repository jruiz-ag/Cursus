/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:40:46 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/27 20:01:42 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual_lst;
	t_list	*next_lst;

	if (!lst || !*lst || !del)
		return ;
	actual_lst = *lst;
	while (actual_lst)
	{
		next_lst = actual_lst->next;
		ft_lstdelone(actual_lst, del);
		actual_lst = next_lst;
	}
	*lst = NULL;
}
/*
void del (void *p)
{
	free(p);
}

int main()
{
	t_list	*t1 = ft_lstnew(ft_strdup("Various things"));
	t_list	*t2 = ft_lstnew(ft_strdup("Two things"));
	t1 -> next = t2;
	ft_lstclear(&t1, del);
}
*/