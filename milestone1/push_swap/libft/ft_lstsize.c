/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 21:18:11 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/28 17:01:57 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cont;

	cont = 0;
	while (lst)
	{
		++cont;
		lst = lst->next;
	}
	return (cont);
}

/*
#include <stdio.h>
int main()
{
	t_list *n1 = ft_lstnew("Initial Node");
	t_list *n2 = ft_lstnew("Second Node");
	n1->next = n2;
	t_list *n3 = ft_lstnew("New Node - Insert");
	printf("%d\n", ft_lstsize(n1));
	ft_lstadd_front(&n1, n3);
	printf("%d", ft_lstsize(n1));
}
*/