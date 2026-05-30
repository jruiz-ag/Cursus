/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:21:07 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:21:08 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_int_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

static void	ft_save_nbr(char *ptr, long long_n, size_t len)
{
	if (long_n == 0)
		ptr[len - 1] = '0';
	while (long_n != 0)
	{
		ptr[len - 1] = (long_n % 10) + '0';
		long_n = long_n / 10;
		--len;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;
	long	n_aux;

	n_aux = n;
	len = ft_int_len(n);
	ptr = ft_calloc((len + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (n < 0)
	{
		ptr[0] = '-';
		ft_save_nbr(ptr, -n_aux, len);
	}
	else
		ft_save_nbr(ptr, n_aux, len);
	return (ptr);
}
/*
int	main(void)
{
	int		n;
	char	*ptr;

	//n = 0;
	//n = -2147483648;
	//n = 2147483647;
	ptr = ft_itoa(n);
	printf("ptr contiene: %s\n", ptr);
	return (0);
}
*/