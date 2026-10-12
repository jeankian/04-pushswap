/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:52:25 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/11 15:44:50 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	str = (char *)malloc(size + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (size--)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	even_char_lower(unsigned int i, char c)
{
	if (((i + 1) % 2) == 0)
	{
		if (c >= 'A' && c <= 'Z')
			c += 32;
	}
	return (c);
}

#include <stdio.h>
int	main(void)
{
	char const	*s = "hElLo WOrLD hIiI";
	char	*new_s = ft_strmapi(s, &even_char_lower);
	printf("new: %s\n", new_s);
	printf("ori: %s\n", s);
	free(new_s);
}*/