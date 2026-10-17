/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:10:30 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:10:30 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
#include <stdint.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

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
*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	sub_len;
	size_t	i;

	if (s == NULL || len == 0)
		return (ft_calloc(1, 1));
	s_len = ft_strlen(s);
	if (start == s_len || start > s_len)
		return (ft_calloc(1, 1));
	sub_len = 0;
	while (s[start + sub_len] && sub_len < len)
		sub_len++;
	substr = malloc((sub_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int	main(void)
{
	printf("%s\n", ft_substr("hallo", 0, 2));
	printf("%s\n", ft_substr("hallo", 0, 0));
	printf("%s\n", ft_substr("hallo", 10, 2));
	printf("%s\n", ft_substr("hallo", 0, 10));
	printf("%s\n", ft_substr("hallo", 5, 10));
	
	return (0);
}
*/
