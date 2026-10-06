/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:50:41 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:50:42 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char	*copy_words(char const *s, int len)
{
	int		i;
	char	*word;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	fill_words(char **res, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = copy_words(&s[i], word_len(&s[i], c));
			if (!res[j])
			{
				while (j > 0)
					free(res[--j]);
				free (res);
				return (0);
			}
			i += word_len(&s[i], c);
			j++;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (!fill_words(res, s, c))
		return (NULL);
	return (res);
}

/*
** FT_SPLIT - PSEUDOCODE SUMMARY
**
** GOAL: split string s by delimiter c into array of word-strings,
**NULL-terminated.
**
** 1) count_words(s, c)
**    - walk s, count transitions from "delimiter/start" -> "non-delimiter"
**    - this = number of words = size needed for res array
**
** 2) word_len(s, c)
**    - given pointer to start of a word, count chars until c or '\0'
**
** 3) copy_words(s, len)
**    - malloc(len + 1)
**    - copy len chars from s, add '\0'
**    - return NULL if malloc fails
**
** 4) fill_words(res, s, c)   <- does the main loop
**    i = 0, j = 0
**    while s[i]:
**        if s[i] is NOT delimiter:
**            len = word_len(&s[i], c)
**            res[j] = copy_words(&s[i], len)
**            if res[j] == NULL:              <-- FREE PART
**                free every res[0..j-1] (already-allocated words)
**                free res itself (the array)
**                return 0 (fail)
**            i += len          (skip past the word just copied)
**            j++               (move to next slot)
**        else:
**            i++               (skip delimiter char)
**    return 1 (success)
**
** 5) ft_split(s, c)   <- coordinator, stays short
**    if s is NULL -> return NULL
**    res = ft_calloc(count_words(s, c) + 1, sizeof(char *))   (+1 for NULL end)
**    if res == NULL -> return NULL
**    if fill_words(res, s, c) fails -> return NULL
**    return res
**
** KEY RULES TO REMEMBER:
** - j only increments AFTER a successful copy_words, so j always
**   equals "how many words are safely allocated so far" -> safe to
**   use for cleanup on failure.
** - use ft_calloc (not malloc) for res so unused slots are NULL by default.
** - free loop pattern on failure:
**       while (j > 0)
**           free(res[--j]);
**       free(res);
** - never call word_len twice for the same word; store in a var (len).
** - keep loop logic in fill_words (not ft_split) to stay under Norm's
**   25-line limit and 5-functions-per-file rule.
*/
