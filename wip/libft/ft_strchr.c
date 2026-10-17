/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:09:19 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:09:19 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	a = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i++;
	}
	if (a == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	printf("ft_strchr(\"hallo\", 'a'): %s | strchr(\"hallo\", 'a'): %s\n", 
		ft_strchr("hallo", 'a'), strchr("hallo", 'a'));
	printf("ft_strchr(\"hallo\", 108): %s | strchr(\"hallo\", 108): %s\n", 
		ft_strchr("hallo", 108), strchr("hallo", 108));
	printf("ft_strchr(\"hallo\", 'h'): %s | strchr(\"hallo\", 'h'): %s\n", 
		ft_strchr("hallo", 'h'), strchr("hallo", 'h'));
	printf("ft_strchr(\"hallo\", 'l'): %s | strchr(\"hallo\", 'l'): %s\n", 
		ft_strchr("hallo", 'l'), strchr("hallo", 'l'));
	printf("is NULL? ft_strchr(\"\", '1'): %d | "
		"is NULL? ft_strchr(\"\", '1'): %d\n", strchr("", '1') == NULL, 
		ft_strchr("", '1') == NULL);
	printf("is NULL? ft_strchr(\"hallo\", '1'): %d | "
		"is NULL? ft_strchr(\"hallo\", '1'): %d\n", 
		strchr("hallo", '1') == NULL, ft_strchr("hallo", '1') == NULL);
	printf("is NULL? ft_strchr(\"hallo\", '\\0'): %d | "
		"is NULL? ft_strchr(\"hallo\", '\\0'): %d\n", 
		strchr("hallo", '\0') == NULL, ft_strchr("hallo", '\0') == NULL);

	return (0);
}
*/
