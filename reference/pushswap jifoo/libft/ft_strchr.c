/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:50:49 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:50:50 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate the first occurrence of c in the string s
char	*ft_strchr(const char *s, int c)
{
	unsigned char	c2;

	c2 = (unsigned char) c;
	while (*s)
	{
		if ((unsigned char)*s == c2)
			return ((char *) s);
		s++;
	}
	if (c2 == '\0')
		return ((char *) s);
	return (NULL);
}
