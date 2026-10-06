/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:49:38 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:49:40 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate the first occurrence of c in s
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*ptr == (unsigned char) c)
			return ((void *) ptr);
		ptr++;
		i++;
	}
	return (NULL);
}
