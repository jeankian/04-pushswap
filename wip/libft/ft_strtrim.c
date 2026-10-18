/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:10:24 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:10:24 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
#include <stdint.h>
#include <stdio.h>

void	*ft_calloc(size_t elnum, size_t elsize)
{
	unsigned char	*ptr;
	size_t			total;
	size_t			i;

	if (elnum != 0 && elsize > (SIZE_MAX / elnum))
		return (NULL);
	if (elnum == 0 || elsize == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
        return (ptr);
	}
	total = elnum * elsize;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}
*/

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (s1 == NULL || set == NULL)
		return (ft_calloc(1, 1));
	i = 0;
	while (s1[i] && (ft_strchr(set, s1[i]) != NULL))
		i++;
	start = i;
	if (start == ft_strlen(s1))
		return (ft_calloc(1, 1));
	i = ft_strlen(s1) - 1;
	while (i > start && (ft_strchr(set, s1[i]) != NULL))
		i--;
	end = i;
	trimmed = malloc((end - start + 2) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
/*
int	main(void)
{
	printf("%s\n", ft_strtrim("hi", "x"));
	printf("%s\n", ft_strtrim("hix", "x"));
	printf("%s\n", ft_strtrim("xxxxhaxxlloxxx", "x"));
	printf("%s\n", ft_strtrim(",xx x,,xhax,xlloxxx", "x ,"));
	printf("%s\n", ft_strtrim("xxxxhaxxlloxxx", ""));
	printf("%s\n", ft_strtrim("", "x"));
	printf("%s\n", ft_strtrim("x", "x"));
	
	return (0);
}
*/