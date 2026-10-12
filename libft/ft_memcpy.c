/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:57:13 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/03 14:30:52 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;
	size_t				i;

	if (!dest || !src || !n)
		return (dest);
	p_dest = (unsigned char *) dest;
	p_src = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[100] = "Geeksfor";
	char	dest[10] = "Sendhelp";
	//char	src[10] = {'a', 'b', 'c', 'd'};
	//char	dest[10] = {'c', 'd', 'a', 'b'};
	//ft_memcpy(dest, src, 4);
	//memcpy(dest, src, 0);
	//ft_memcpy(src + 5, src, strlen(src) + 1);
	//memcpy(src + 5, src, strlen(src) + 1);
	printf("%s", dest);
}*/