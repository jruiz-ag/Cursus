/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 20:41:48 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/27 20:00:37 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*sol;

	sol = ft_calloc(1, sizeof(t_list));
	if (!sol)
		return (NULL);
	sol->content = content;
	sol->next = NULL;
	return (sol);
}
/*
#include <stdio.h>
int main()
{
	char *aux = "Proof";
	t_list *root = ft_lstnew(aux);
	printf("%s\n", (char *)root->content);
	printf("%p", root->next);
}
*/