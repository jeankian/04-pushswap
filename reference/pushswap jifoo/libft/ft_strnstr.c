/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:51:50 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:51:52 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate the first occurrence of the null-terminated string
//to_find in the string str, where not more than len characters
//are searched
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t			i;
	size_t			j;
	const char		*s;
	const char		*f;

	if (*to_find == '\0')
		return ((char *) str);
	i = 0;
	while (i < len && *str)
	{
		s = str;
		f = to_find;
		j = i;
		while (*s == *f && *f && j < len)
		{
			s++;
			f++;
			j++;
		}
		if (*f == '\0')
			return ((char *) str);
		str++;
		i++;
	}
	return (0);
}
