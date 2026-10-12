/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 16:27:03 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/12 09:31:46 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int	main(void)
{
	char	src[] = "Hello world";
	char	dst[] = " hi";

	printf("%s\n", dst);
	printf("%zu\n", ft_strlcpy(dst, src, 13));
	//printf("%zu\n", strlcpy(dst, src, 13));
	printf("%s", dst);
}*/
