/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:08:38 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:08:38 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*start;
	size_t	i;

	start = s;
	i = 0;
	while (i < n)
	{
		start[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	buf1[10] = "hallo";
	char	buf2[10] = "hallo";
	printf("ft_memset(\"hallo\", 'x', 3): %s | "
		"memset(\"hallo\", 'x', 3): %s\n", 
		(char *)ft_memset(buf1, 'x', 3), (char *)memset(buf2, 'x', 3));
	strcpy(buf1, "hallo");
	strcpy(buf2, "hallo");
	int		n1 = 0;
	printf("ft_memset(\"hallo\", 'x', 0): %s | "
		"memset(\"hallo\", 'x', 0): %s\n", 
		(char *)ft_memset(buf1, 'x', n1), (char *)memset(buf2, 'x', n1));
	strcpy(buf1, "hallo");
	strcpy(buf2, "hallo");
	printf("ft_memset(\"hallo\", 'x', 7): %s | "
		"memset(\"hallo\", 'x', 7): %s\n", 
		(char *)ft_memset(buf1, 'x', 7), (char *)memset(buf2, 'x', 7));
	strcpy(buf1, "hallo");
	strcpy(buf2, "hallo");
	printf("ft_memset(\"hallo\", 'x', 10): %s | "
		"memset(\"hallo\", 'x', 10): %s\n", 
		(char *)ft_memset(buf1, 'x', 10), (char *)memset(buf2, 'x', 10));

	return (0);
}
*/