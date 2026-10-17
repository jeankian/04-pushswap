/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:09:24 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:09:24 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
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

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = ft_strlen(s);
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int	main(void)
{
	char	*strdup_a1 = ft_strdup("hallo");
	char	*strdup_a2 = strdup("hallo");
	char	*strdup_b1 = ft_strdup("");
	char	*strdup_b2 = strdup("");
	printf("ft_strdup(\"hallo\"): %s | strdup(\"hallo\"): %s\n", 
		strdup_a1, strdup_a2);
	printf("ft_strdup(\"\"): %s | strdup(\"\"): %s\n", strdup_b1, strdup_b2);
	free(strdup_a1);
	free(strdup_a2);
	free(strdup_b1);
	free(strdup_b2);
	
	return (0);
}
*/