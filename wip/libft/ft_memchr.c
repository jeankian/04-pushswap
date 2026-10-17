/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:08:14 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:08:14 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*tmp;

	tmp = s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((void *)&tmp[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("ft_memchr(\"hallo\", 'a', 2): %s | "
		"memchr(\"hallo\", 'a', 2): %s\n", 
		(char *)ft_memchr("hallo", 'a', 2), (char *)memchr("hallo", 'a', 2));
	printf("ft_memchr(\"hallo\", 'h', 5): %s | "
		"memchr(\"hallo\", 'h', 5): %s\n", 
		(char *)ft_memchr("hallo", 'h', 5), (char *)memchr("hallo", 'h', 5));
	printf("is NULL? ft_memchr(\"hallo\", '1', 5): %d | "
		"is NULL? memchr(\"hallo\", '1', 5): %d\n", 
		ft_memchr("hallo", '1', 5) == NULL, memchr("hallo", '1', 5) == NULL);
	printf("is NULL? ft_memchr(\"\", '1', 0): %d | "
		"is NULL? memchr(\"\", '1', 0): %d\n", 
		ft_memchr("", '1', 0) == NULL, memchr("", '1', 0) == NULL);
	printf("is NULL? ft_memchr(\"hallo\", '\\0', 5): %d | "
		"is NULL? memchr(\"hallo\", '\\0', 5): %d\n", 
		ft_memchr("hallo", '\0', 5) == NULL, memchr("hallo", '\0', 5) == NULL);

	return (0);
}
*/