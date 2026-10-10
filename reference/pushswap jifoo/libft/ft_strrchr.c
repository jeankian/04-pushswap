/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:51:57 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:51:58 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate the last occurrence of c in the string s
char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	c2;

	i = 0;
	while (s[i])
		i++;
	c2 = (unsigned char) c;
	while (1)
	{
		if ((unsigned char) s[i] == c2)
			return ((char *) s + i);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
