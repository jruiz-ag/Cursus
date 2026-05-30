/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:18:48 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:58:28 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_move_spaces(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
		str++;
	return (str);
}

static int	ft_check_sign(char *str)
{
	int	sign;
	int	minus;

	sign = 0;
	minus = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			++minus;
		++sign;
		str++;
	}
	if (sign > 1)
		return (1);
	else if (minus == 1)
		return (2);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	*str_aux;
	int		nbr;
	int		sign;

	nbr = 0;
	str_aux = (char *)nptr;
	sign = ft_check_sign(str_aux);
	str_aux = ft_move_spaces(str_aux);
	while ((*str_aux >= '0' && *str_aux <= '9') && *str_aux != '\0')
	{
		nbr = nbr * 10 + (*str_aux - '0');
		str_aux++;
	}
	if (sign == 1)
		return (0);
	else if (sign == 2)
		return (-nbr);
	return (nbr);
}

/*int	main(void)
{
	char	src_1[] = "\t\v\f\r\n \f-06050";
	int		ret;
	int		ft_ret;

	ret = atoi(src_1);
	ft_ret = ft_atoi(src_1);
	printf("El ret es: %i\n", ret);
	printf("El ft_ret es: %i\n", ft_ret);
	return (0);
}*/