/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:51:31 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/21 17:01:30 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	size_t			length;
	unsigned int	end;

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
	while (i < length)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

/*#include <stdio.h>
int	main(void)
{
	char const	*s = "hello world";
	char	*substr = ft_substr(s, 2, 6);

	printf("%s\n", substr);
	free(substr);
}*/

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char const	*s = "test";
	char	*substr = ft_substr(s, 0, 42000);

	printf("%s\n", substr);
	free(substr);
}*/