/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:09:48 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:09:48 by jkian            ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	if (dsize == 0)
		return (slen);
	i = 0;
	while (i + 1 < dsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
/*
int	main(void)
{
	char	strlcpy_d[20] = "pine"; //destination
	char	strlcpy_s1[20] = "appl"; //source
	char	strlcpy_s2[20] = " "; //source
	char	strlcpy_s3[20] = ""; //source
	printf("ft_strlcpy(des: \"pine\", sou: \"appl\", 10): %zu | "
		"strlcpy(des: \"pine\", sou: \"appl\", 10): %zu\n", 
		ft_strlcpy(strlcpy_d, strlcpy_s1, 10), 
		strlcpy(strlcpy_d, strlcpy_s1, 10));
	printf("ft_strlcpy(des: \"pine\", sou: \"appl\", 4): %zu | "
		"strlcpy(des: \"pine\", sou: \"appl\", 4): %zu\n", 
		ft_strlcpy(strlcpy_d, strlcpy_s1, 4), 
		strlcpy(strlcpy_d, strlcpy_s1, 4));
	printf("ft_strlcpy(des: \"pine\", sou: \"appl\", 0): %zu | "
		"strlcpy(des: \"pine\", sou: \"appl\", 0): %zu\n", 
		ft_strlcpy(strlcpy_d, strlcpy_s1, 0), 
		strlcpy(strlcpy_d, strlcpy_s1, 0));
	printf("ft_strlcpy(des: \"pine\", sou: \" \", 2): %zu | "
		"strlcpy(des: \"pine\", sou: \" \", 2): %zu\n", 
		ft_strlcpy(strlcpy_d, strlcpy_s2, 2), 
		strlcpy(strlcpy_d, strlcpy_s2, 2));
	printf("ft_strlcpy(des: \"pine\", sou: \"\", 2): %zu | "
		"strlcpy(des: \"pine\", sou: \"\", 2): %zu\n", 
		ft_strlcpy(strlcpy_d, strlcpy_s3, 2), 
		strlcpy(strlcpy_d, strlcpy_s3, 2));
	//dsize is size of destination buffer, w space for null terminator
	//If return value >= dsize, truncation occurred
	//returns source len
	
	return (0);
}
*/
