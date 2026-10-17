/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:10:13 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:10:13 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	if (little[0] == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	i = 0;
	while (i + l_len <= len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && j < l_len)
			j++;
		if (j == l_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("ft_strnstr(\"hallo\", \"hallo\", 5): %s\n", 
		ft_strnstr("hallo", "hallo", 5));
	printf("ft_strnstr(\"hallo\", \"al\", 2): %s\n", 
		ft_strnstr("hallo", "al", 2));
	printf("ft_strnstr(\"hallo\", \"hallohallo\", 12): %s\n", 
		ft_strnstr("hallo", "hallohallo", 12));
	printf("ft_strnstr(\"hallo\", \"o\", 5): %s\n", 
		ft_strnstr("hallo", "o", 5));
	printf("ft_strnstr(\"hallo! !hi\", \"hi\", 10): %s\n", 
		ft_strnstr("hallo! !hi", "hi", 10));
	printf("ft_strnstr(\"hallo\", \"\", 7): %s\n", 
		ft_strnstr("hallo", "", 7));
	printf("ft_strnstr(\"\", \"h\", 3): %s\n", ft_strnstr("", "h", 3));
	printf("ft_strnstr(\"\", \"\", 3): %s\n", ft_strnstr("", "", 3));
	printf("ft_strnstr(\"hallo\", \"al\", 0): %s\n", 
		ft_strnstr("hallo", "al", 0));

	return (0);
}
*/