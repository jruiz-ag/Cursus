/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruiz-ag <jruiz-ag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:50:12 by jruiz-ag          #+#    #+#             */
/*   Updated: 2026/04/24 20:36:08 by jruiz-ag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	max;

	if (nmemb == 0 || size == 0)
		max = 0;
	else if (nmemb > ((size_t)-1 / size))
		return (NULL);
	else
		max = nmemb * size;
	res = malloc(max);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, max);
	return (res);
}
/*
#include <stdio.h>
#include <stdint.h>
int main()
{
	int *ft_nums = ft_calloc(2, sizeof(int));
	ft_nums[0] = 1;
	ft_nums[1] = 2;
	printf("%d %d\n", ft_nums[0], ft_nums[1]);

	int *nums = calloc(2, sizeof(int));
	nums[0] = 1;
	nums[1] = 2;
	printf("%d %d\n", nums[0], nums[1]);

	int *ft_nums_1 = ft_calloc(SIZE_MAX, 2);
	if (!ft_nums_1)
    	printf("overflow detectado\n");

	int *nums_1 = calloc(SIZE_MAX, 2);
	if (!nums_1)
    	printf("overflow detectado\n");

	int *ft_nums_2 = ft_calloc(0, 1);
	free(ft_nums_2);

	int *nums_2 = ft_calloc(0, 1);
	free(nums_2);
}
*/