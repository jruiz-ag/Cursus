/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:24:18 by lupin             #+#    #+#             */
/*   Updated: 2026/04/26 14:14:30 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*new_content;

	new_lst = NULL;
	if (!lst || !del || !f || !lst->content)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*
static void	free_content(void *content)
{
	free(content);
}

static void	*map_to_uppercase(void *content)
{
	char	*src;
	char	*mapped;
	int		i;

	src = (char *)content;
	mapped = ft_strdup(src);
	if (!mapped)
		return (NULL);
	i = 0;
	while (mapped[i])
	{
		mapped[i] = (char)ft_toupper((unsigned char)mapped[i]);
		i++;
	}
	return (mapped);
}

static void	print_list(char *label, t_list *lst)
{
	int	index;

	printf("%s\n", label);
	index = 0;
	while (lst)
	{
		printf("  [%d] \"%s\"\n", index, (char *)lst->content);
		lst = lst->next;
		index++;
	}
}

int	main(void)
{
	t_list	*original;
	t_list	*mapped;

	original = NULL;
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("hola")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("42 Malaga")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("LiBfT test")));
	mapped = ft_lstmap(original, map_to_uppercase, free_content);
	print_list("Lista original:", original);
	print_list("\nLista mapeada:", mapped);
	ft_lstclear(&original, free_content);
	ft_lstclear(&mapped, free_content);
	return (0);
}
*/