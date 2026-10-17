/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:10:08 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:10:08 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	printf("ft_strncmp(\"hallo\", \"hallo\", 5): %d | "
		"strncmp(\"hallo\", \"hallo\", 5): %d\n", 
		ft_strncmp("hallo", "hallo", 5), strncmp("hallo", "hallo", 5));
	printf("ft_strncmp(\"hallo\", \"hal\", 5): %d | "
		"strncmp(\"hallo\", \"hal\", 5): %d\n", 
		ft_strncmp("hallo", "hal", 5), strncmp("hallo", "hal", 5));
	printf("ft_strncmp(\"hallo\", \"ha123\", 3): %d | "
		"strncmp(\"hallo\", \"ha123\", 3): %d\n", 
		ft_strncmp("hallo", "ha123", 3), strncmp("hallo", "ha123", 3));
	printf("ft_strncmp(\"hallo\", \"allo\", 0): %d | "
		"strncmp(\"hallo\", \"allo\", 0): %d\n", 
		ft_strncmp("hallo", "allo", 0), strncmp("hallo", "allo", 0));
	printf("ft_strncmp(\"hallo\", \"allo\", 1): %d | "
		"strncmp(\"hallo\", \"allo\", 1): %d\n", 
		ft_strncmp("hallo", "allo", 1), strncmp("hallo", "allo", 1));
	printf("ft_strncmp(\"hallo\", \"hi\", 3): %d | "
		"strncmp(\"hallo\", \"hi\", 3): %d\n", 
		ft_strncmp("hallo", "hi", 3), strncmp("hallo", "hi", 3));
	printf("ft_strncmp(\"hallo\", \"\", 5): %d | "
		"strncmp(\"hallo\", \"\", 5): %d\n", 
		ft_strncmp("hallo", "", 5), strncmp("hallo", "", 5));

	return (0);
}
*/