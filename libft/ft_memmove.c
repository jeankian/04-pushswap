/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:52:20 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/03 14:31:09 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			i;

	if (!src || !dest || !n)
		return (dest);
	p_dest = (unsigned char *) dest;
	p_src = (unsigned char *) src;
	i = n - 1;
	if (dest <= src)
	{
		while (n--)
			*p_dest++ = *p_src++;
	}
	else
	{
		while (n--)
		{
			p_dest[i] = p_src[i];
			i--;
		}
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s[] = "send help";
//	char d[100] = " ";
	ft_memmove(s + 2, s, 3);
//	memmove(s + 2, s, 3);
	printf("%s", s);
	return (0);
}*/