/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:14:03 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/28 15:45:48 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	word_length(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*get_word(char const *s, char c)
{
	int		word_len;

	word_len = word_length(s, c);
	return (ft_substr(s, 0, word_len));
}

static char	**free_all(char **outer, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(outer[i]);
		i++;
	}
	free(outer);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**outer;
	int		i;

	if (!s)
		return (NULL);
	outer = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!outer)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			outer[i] = get_word(s, c);
			if (!(outer[i]))
				return (free_all(outer, i));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	outer[i] = NULL;
	return (outer);
}

/*#include <stdio.h>
int	main(void)
{
	char const	*s = "    hello world  hiiii ";
	char	c = ' ';
	char	**split = ft_split(s, c);
	if (!split)
		return (0);
	int	i;
	
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	free_all(split, i);
	return (0);
}*/