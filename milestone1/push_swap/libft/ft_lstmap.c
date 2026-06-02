/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:42:13 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/28 16:52:29 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*init;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	init = ft_lstnew(f(lst->content));
	if (!init)
		return (NULL);
	node = init;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		if (!node->next)
		{
			ft_lstclear(&init, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	node->next = NULL;
	return (init);
}

/*
void del (void *p)
{
	free(p);
}

void	*f(void *content)
{
	char	*s;

	s = ft_strdup((char *)content);
	s[0] = 'a';
	return (s);
}
#include <stdio.h>
int main()
{
	t_list *n1 = ft_lstnew(ft_strdup("Initial Node"));
	t_list *n2 = ft_lstnew(ft_strdup("Second Node"));
	t_list *n3 = ft_lstnew(ft_strdup("Third Node - Insert"));
	ft_lstadd_back(&n1, n2);
	ft_lstadd_back(&n1, n3);
	t_list *new = ft_lstmap(n1, f, del);

	while (n1)
	{
		printf("%s\n", (char *)n1->content);
		n1 = n1->next;
	}

	ft_lstclear(&n1, del);
	while (new)
	{
		printf("%s\n", (char *)new->content);
		new = new->next;
	}
	ft_lstclear(&new, del);
}
*/