/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:59:43 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/27 19:58:23 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int main()
{
	t_list *n1 = ft_lstnew("Initial Node");
	t_list *n2 = ft_lstnew("Second Node");
	n1->next = n2;
	t_list *n3 = ft_lstnew("New Node - Insert");
	ft_lstadd_front(&n1, n3);
	while(n1->next != NULL)
	{
		printf("Content: %s.", (char *)n1->content);
		printf(" Next direction: %p\n", n1->next);
		n1 = n1->next;
	}
	printf("Content: %s.", (char *)n1->content);
	printf(" Next direction: %p\n", n1->next);
}
*/