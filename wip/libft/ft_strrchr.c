/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:10:19 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:10:19 by jkian            ###   ########.fr       */
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

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	a;

	a = (char)c;
	i = ft_strlen(s);
	if (a == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		i--;
		if (s[i] == a)
			return ((char *)&s[i]);
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("ft_strrchr(\"hallo\", 'a'): %s | ft_strrchr(\"hallo\", 'a'): %s\n", 
		strrchr("hallo", 'a'), ft_strrchr("hallo", 'a'));
	printf("ft_strrchr(\"hallo\", 'h'): %s | ft_strrchr(\"hallo\", 'h'): %s\n", 
		strrchr("hallo", 'h'), ft_strrchr("hallo", 'h'));
	printf("ft_strrchr(\"hallo\", 'l'): %s | ft_strrchr(\"hallo\", 'l'): %s\n", 
		strrchr("hallo", 'l'), ft_strrchr("hallo", 'l'));
	printf("is NULL? ft_strrchr(\"\", '1'): %d | "
		"is NULL? ft_strrchr(\"\", '1'): %d\n", 
		strrchr("", '1') == NULL, ft_strrchr("", '1') == NULL);
	printf("is NULL? ft_strrchr(\"hallo\", '1'): %d | "
		"is NULL? ft_strrchr(\"hallo\", '1'): %d\n", 
		strrchr("hallo", '1') == NULL, ft_strrchr("hallo", '1') == NULL);
	printf("is NULL? ft_strrchr(\"hallo\", '\\0'): %d | "
		"is NULL? ft_strrchr(\"hallo\", '\\0'): %d\n", 
		strrchr("hallo", '\0') == NULL, ft_strrchr("hallo", '\0') == NULL);

	return (0);
}
*/