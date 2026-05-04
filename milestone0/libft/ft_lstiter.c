/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:06:20 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/28 15:29:21 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void del (void *p)
{
	free(p);
}

void	f(void *content)
{
	((char *)content)[0] = 'C';
}
#include <stdio.h>
int main()
{
	t_list *n1 = ft_lstnew(ft_strdup("Initial Node"));
	t_list *n2 = ft_lstnew(ft_strdup("Second Node"));
	t_list *n3 = ft_lstnew(ft_strdup("Third Node - Insert"));
	t_list *aux;
	ft_lstadd_back(&n1, n2);
	ft_lstadd_back(&n1, n3);

	aux = n1;
	while (aux)
	{
		printf("%s\n", (char *)aux->content);
		aux = aux->next;
	}
	ft_lstiter(n1, f);

	aux = n1;
	while (aux)
	{
		printf("%s\n", (char *)aux->content);
		aux = aux->next;
	}
	ft_lstclear(&n1, del);
}
*/