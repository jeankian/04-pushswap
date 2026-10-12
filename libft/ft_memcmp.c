/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:13:12 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/28 11:35:50 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	p_s1 = (unsigned char *) s1;
	p_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (p_s1[i] == p_s2[i] && i < n - 1)
		i++;
	return (p_s1[i] - p_s2[i]);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char	*s1 = "hi";
	const char	*s2 = "hello";

	printf("mine:   %i\n", ft_memcmp(s1, s2, 0));
	printf("actual: %i", memcmp(s1, s2, 0));
}*/