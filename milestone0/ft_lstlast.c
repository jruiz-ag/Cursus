/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:04:41 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/27 18:08:56 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while ((lst -> next) != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

/*
#include <stdio.h>
int main()
{
	t_list *n1 = ft_lstnew("Initial Node");
	t_list *n2 = ft_lstnew("Second Node");
	n1->next = n2;
	printf("%s\n", (char *)ft_lstlast(n1)->content);
	t_list *n3 = ft_lstnew("Third Node - Insert");
	n2->next = n3;
	printf("%s", (char *)ft_lstlast(n1)->content);
}
*/