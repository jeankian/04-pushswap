/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:52:34 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:52:35 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//finds substring from string
//len + 1 as strlcpy reads one char before null terminator
//clamp len so it doesnt read out of bounds
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	slen;

	slen = ft_strlen(s);
	if (start > slen)
		start = slen;
	if (len > slen - start)
		len = slen - start;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len + 1);
	return (dest);
}
