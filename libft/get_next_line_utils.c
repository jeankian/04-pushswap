/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:47:30 by xin-jili          #+#    #+#             */
/*   Updated: 2026/09/23 14:09:17 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr_gnl(const char *s, unsigned int start, size_t len)
{
	size_t			length;
	size_t			i;
	unsigned int	end;
	char			*substr;

	if (!s)
		return (NULL);
	end = ft_strlen(s);
	length = end - start;
	if (start > end)
		length = 0;
	if (length > len)
		length = len;
	substr = (char *)malloc((length + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (length--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

void	ft_strcpy_gnl(char *dest, const char *src)
{
	size_t			i;

	if (!src || !dest)
		return ;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
