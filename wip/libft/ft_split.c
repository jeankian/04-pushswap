/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:09:13 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:09:13 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static size_t	wordcount(const char *s, char c)
{
	size_t	wcount;
	size_t	i;

	wcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wcount++;
		i++;
	}
	return (wcount);
}

static char	*wordptr(const char *s, char c, size_t start)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	while (s[start + i] && s[start + i] != c)
		i++;
	len = i;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	leak_cleanup(char **ptrs, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(ptrs[i]);
		i++;
	}
	free(ptrs);
}

char	**ft_split(const char *s, char c)
{
	char	**ptrs;
	size_t	i;
	size_t	j;

	ptrs = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (ptrs == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			ptrs[j] = wordptr(s, c, i);
			if (ptrs[j] == NULL)
			{
				leak_cleanup(ptrs, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	ptrs[j] = NULL;
	return (ptrs);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**split;
	int		i = 0;

	split = ft_split("     apple orange   pi lemon", ' ');
	
	split = ft_split("", ' ');
	
	split = ft_split("     ", ' ');
	
	split = ft_split("hallo", ' ');
	
	split = ft_split("hallo    ", ' ');
	
	split = ft_split("a", 'a');
		
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	
	i = 0;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
	
	return (0);
}
*/
