/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:37:37 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/24 18:03:31 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(const char *big, const char *little, size_t len, size_t i)
{
	size_t	little_i;
	size_t	big_i;

	little_i = 0;
	big_i = i;
	while (little[little_i] && big_i < len)
	{
		if (big[big_i] != little[little_i])
			break ;
		big_i++;
		little_i++;
	}
	if (!little[little_i])
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == *little)
		{
			if (match(big, little, len, i))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	const char *big = "hello I don't want to continue doing libft";
	const char *little = "do";

	printf("mine:   %s\n", ft_strnstr(big, little, 40));
	printf("actual: %s", strnstr(big, little, 40));
}*/