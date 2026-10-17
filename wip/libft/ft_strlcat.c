/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:09:42 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:09:42 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
//cc ft_strlcat.c -lbsd

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dsize < dlen)
		return (slen + dsize);
	i = dlen;
	j = 0;
	while (i + 1 < dsize && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}
/*
int	main(void)
{
	char	strlcat_d1[20] = "pine"; //destination
	char	strlcat_d2[20] = "pine"; //destination
	char	strlcat_d3[20] = ""; //destination
	char	strlcat_d4[20] = ""; //destination
	char	strlcat_s[20] = "apple"; //source
	printf("ft_strlcat(des: \"pine\", sou: \"apple\", 10): %zu | "
		"strlcat(des: \"pine\", sou: \"apple\", 10): %zu\n", 
		ft_strlcat(strlcat_d1, strlcat_s, 10), 
		strlcat(strlcat_d2, strlcat_s, 10));
	strcpy(strlcat_d1, "pine");
	strcpy(strlcat_d2, "pine");
	printf("ft_strlcat(des: \"pine\", sou: \"apple\", 3): %zu | "
		"strlcat(des: \"pine\", sou: \"apple\", 3): %zu\n", 
		ft_strlcat(strlcat_d1, strlcat_s, 3), 
		strlcat(strlcat_d2, strlcat_s, 3));
	strcpy(strlcat_d1, "pine");
	strcpy(strlcat_d2, "pine");
	printf("ft_strlcat(des: \"pine\", sou: \"apple\", 0): %zu | "
		"strlcat(des: \"pine\", sou: \"apple\", 0): %zu\n", 
		ft_strlcat(strlcat_d1, strlcat_s, 0), 
		strlcat(strlcat_d2, strlcat_s, 0));
	printf("ft_strlcat(des: \"\", sou: \"apple\", 2): %zu | "
		"strlcat(des: \"\", sou: \"apple\", 2): %zu\n", 
		ft_strlcat(strlcat_d3, strlcat_s, 2), 
		strlcat(strlcat_d4, strlcat_s, 2));
	//returns destination len + source len OR 
	//returns source len + dsize if dsize < destination len

	return (0);
}
*/
