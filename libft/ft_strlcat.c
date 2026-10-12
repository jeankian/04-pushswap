/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:10:47 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/03 14:32:07 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	append_size;
	size_t	i;

	src_len = ft_strlen(src);
	if (!dst)
		return (size + src_len);
	dst_len = ft_strlen(dst);
	append_size = size - dst_len - 1;
	i = 0;
	if (dst_len >= size)
		return (size + src_len);
	while (append_size-- && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	//char	dst[] = "\0";
	const char	src[]= "me";

	printf("mine: %zu. ", ft_strlcat(dst, src, 10));
	printf("%s\n", dst);
	// printf("actual: %zu. ", strlcat(NULL, src, 9));
	// printf("%s\n", dst);
}*/