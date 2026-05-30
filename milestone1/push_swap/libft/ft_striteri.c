/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:21:35 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:21:36 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	s_len;
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		f(i, &s[i]);
		++i;
	}
}

/*void	ft_false_strrchr(unsigned int c, char *s)
{
	int		i;

	i = (int)c;
	i = i + 1;
	if ((*s >= 'A' && *s < 'Z')	|| (*s >= 'a' && *s < 'z'))
		*s = *s + 1;
}

int	main(void)
{
	char	s[] = "Odqqn";

	ft_striteri(s, ft_false_strrchr);
	printf("s contiene: %s\n", s);
	return (0);
}*/