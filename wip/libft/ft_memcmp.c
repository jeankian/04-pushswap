/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:08:20 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:08:20 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*t1;
	const unsigned char	*t2;

	i = 0;
	t1 = s1;
	t2 = s2;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return ((unsigned char)t1[i] - (unsigned char)t2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	unsigned char	memcmp_b1[10] = {'h', 'i', '2', '#', 'o'};
	unsigned char	memcmp_b2[10] = {'h', 'i', '2', '#', 'o'};
	printf("ft_memcmp('hi2#o', 'hi2#o', 7): %d | "
		"memcmp('hi2#o', 'hi2#o', 7): %d\n", 
		ft_memcmp(memcmp_b1, memcmp_b2, 7), memcmp(memcmp_b1, memcmp_b2, 7));
	unsigned char	memcmp_b3[10] = {'h', 'i', '\0', '#', 'o'};
	unsigned char	memcmp_b4[10] = {'h', 'i', '\0', '9', 'o'};
	printf("ft_memcmp('hi\\0#o', 'hi\\09o', 5): %d | "
		"memcmp('hi\\0#o', 'hi\\09o', 5): %d\n", 
		ft_memcmp(memcmp_b3, memcmp_b4, 5), memcmp(memcmp_b3, memcmp_b4, 5));
	unsigned char	memcmp_b5[10] = {'h', 'i', '\0', '#', 'o'};
	printf("ft_memcmp(\"halloo\", 'hi\\0#o', 7): %d | "
		"memcmp(\"halloo\", 'hi\\0#o', 7): %d\n", 
		ft_memcmp("halloo", memcmp_b5, 7), memcmp("halloo", memcmp_b5, 7));
	printf("ft_memcmp(\"hallo\", \"ha123\", 3): %d | "
		"memcmp(\"hallo\", \"ha123\", 3): %d\n", 
		ft_memcmp("hallo", "ha123", 3), memcmp("hallo", "ha123", 3));
	printf("ft_memcmp(\"hallo\", \"allo\", 0): %d | "
		"memcmp(\"hallo\", \"allo\", 0): %d\n", 
		ft_memcmp("hallo", "allo", 0), memcmp("hallo", "allo", 0));
	printf("ft_memcmp(\"hallo\", \"hi\", 3): %d | "
		"memcmp(\"hallo\", \"hi\", 3): %d\n", 
		ft_memcmp("hallo", "hi", 3), memcmp("hallo", "hi", 3));
	printf("ft_memcmp(\"hallo\", \"\", 1): %d | "
		"memcmp(\"hallo\", \"\", 1): %d\n", 
		ft_memcmp("hallo", "", 1), memcmp("hallo", "", 1));

	return (0);
}
*/