/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:50:26 by lupin             #+#    #+#             */
/*   Updated: 2026/05/23 15:30:55 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_node(const int content)
{
	t_stack	*nodo;

	nodo = ft_calloc(1, sizeof(t_stack));
	if (!nodo)
		return (NULL);
	nodo->value = content;
	nodo->next = NULL;
	nodo->prev = NULL;
	return (nodo);
}

void	add_node_front(t_stack **lst, t_stack *new)
{
	t_stack	*first;

	if (!new)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		first = first_node(*lst);
		first->prev = new;
		new->next = first;
		*lst = new;
	}
}

void	add_node_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		last = last_node(*lst);
		last->next = new;
		new->prev = last;
	}
}

int	lst_size(const t_stack *lst)
{
	int		size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	free_stack(t_stack **lst)
{
	t_stack	*current;
	t_stack	*next_node;

	if (!*lst)
		return ;
	current = first_node(*lst);
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = NULL;
}
