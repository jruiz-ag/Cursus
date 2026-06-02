/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:09:44 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/27 19:53:41 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
#include <stdio.h>
int main()
{
	t_list *n1 = ft_lstnew("Initial Node");
	t_list *n2 = ft_lstnew("Second Node");
	ft_lstadd_back(&n1, n2);
	printf("%s\n", (char *)ft_lstlast(n1)->content);
	t_list *n3 = ft_lstnew("Third Node - Insert");
	ft_lstadd_back(&n1, n3);
	printf("%s", (char *)ft_lstlast(n1)->content);
}
*/