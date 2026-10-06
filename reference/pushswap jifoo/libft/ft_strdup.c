/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:50:54 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:50:55 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*dest;
	char	*p;

	len = ft_strlen(src) + 1;
	dest = malloc(len);
	if (!dest)
		return (NULL);
	p = dest;
	while (*src != '\0')
		*p++ = *src++;
	*p = '\0';
	return (dest);
}
