/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:16:52 by lupin             #+#    #+#             */
/*   Updated: 2026/04/20 19:52:57 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = 0;
	if (size > 0 && dst_len < size)
	{
		while (dst[i] != '\0')
			++i;
		while (src[j] != '\0' && j < (size - dst_len - 1))
		{
			dst[i] = src[j];
			++i;
			++j;
		}
		dst[i] = '\0';
		return (dst_len + src_len);
	}
	return (src_len + size);
}

/*int	main(void)
{
	char	ft_dst[16] = "perrito";
	char	ft_src[] = " malvado";
	char	dst[16] = "perrito";
	char	src[] = " malvado";
	size_t	dstsize = 1;
	size_t	ft_ret;
	size_t	ret;

	ft_ret = ft_strlcat(ft_dst, ft_src, dstsize);
	ret = strlcat(dst, src, dstsize);
	printf("El ft_ret es: %zu\n", ft_ret);
	printf("El ret es: %zu\n", ret);
	printf("El ft_dst contiene: %s\n", ft_dst);
	printf("El dst contiene: %s\n", dst);
	return (0);
}*/