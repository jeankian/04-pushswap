/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 14:11:12 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/21 15:24:15 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	if (!s)
		return (NULL);
	p = (unsigned char *) s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = "send help";
	int	c = 'e';
	char	*result;

	result = ft_memchr(s, c, 8);
	//result = memchr(s, c, 8);
	printf("%s\n", result);
}*/

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int s[] = {9, 5, 0, -1, 8, 10};
	int s1[] = {9, 5, 0, -1, 8, 10};
	int	c = -1;

	char	*result = ft_memchr(s, c, 6);
	char	*result1 = memchr(s1, c, 8);
	printf("%s\n", result);
	printf("%s\n", result1);
}*/

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int s[] = {-49, 49, 1, -1, 0, -2, 2};
	int	c = -1;

	printf("%s\n", (char *)ft_memchr(s, c, 6));
	printf("%s\n", (char *)memchr(s, c, 6));
}*/