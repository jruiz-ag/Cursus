/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:54:32 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/27 19:59:26 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
int main()
{
	t_list	*t1 = ft_lstnew(ft_strdup("Various things"));
	t_list	*t2 = ft_lstnew(ft_strdup("Two things"));
	t1 -> next = t2;
	ft_lstdelone(t1, free);
}
*/