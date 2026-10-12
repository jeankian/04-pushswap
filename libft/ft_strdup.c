/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:03:38 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/24 11:22:04 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str_dup;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	str_dup = (char *)malloc((s_len + 1) * sizeof(char));
	if (!str_dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_dup[i] = s[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s = "hello world";
	char	*str_dup;

	str_dup = ft_strdup(s);
	//str_dup = strdup(s);
	printf("%s", str_dup);
	free(str_dup);
}*/