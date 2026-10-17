/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:08:32 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:08:32 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
*/

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	const char	*sou;
	char		*des;
	size_t		i;

	sou = s2;
	des = s1;
	if (des < sou)
	{
		i = 0;
		while (i < n)
		{
			des[i] = sou[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			des[i] = sou[i];
		}
	}
	return (s1);
}
/*
int	main(void)
{
	char	memmove_a1[20] = "12345abcde";
	char	memmove_b1[20] = "12345abcde";
	printf("ft_memmove(des: \"12345abcde\", sou: buf + 5, 1): %s | "
		"memmove(des: \"12345abcde\", sou: buf + 5, 1): %s\n", 
		(char *)ft_memmove(memmove_a1, memmove_a1 + 5, 1), 
		(char *)memmove(memmove_b1, memmove_b1 + 5, 1));
	strcpy(memmove_a1, "12345abcde");
	strcpy(memmove_b1, "12345abcde");
	printf("ft_memmove(des: \"12345abcde\", sou: buf + 5, 5): %s | "
		"memmove(des: \"12345abcde\", sou: buf + 5, 5): %s\n", 
		(char *)ft_memmove(memmove_a1, memmove_a1 + 5, 5), 
		(char *)memmove(memmove_b1, memmove_b1 + 5, 5));
	strcpy(memmove_a1, "12345abcde");
	strcpy(memmove_b1, "12345abcde");
	printf("ft_memmove(des: \"12345abcde\", sou: buf + 5, 9): %s | "
		"memmove(des: \"12345abcde\", sou: buf + 5, 9): %s\n", 
		(char *)ft_memmove(memmove_a1, memmove_a1 + 5, 9), 
		(char *)memmove(memmove_b1, memmove_b1 + 5, 9));
	printf("\n");
	strcpy(memmove_a1, "12345abcde");
	strcpy(memmove_b1, "12345abcde");
	printf("ft_mmove(des: \"12345abcde\" at buf + 5, sou: buf + 0, 1): %s | "
		"memmove(des: \"12345abcde\" at buf + 5, sou: buf + 0, 1): %s\n", 
		(char *)ft_memmove(memmove_a1 + 5, memmove_a1, 1), 
		(char *)memmove(memmove_b1 + 5, memmove_b1, 1));
	strcpy(memmove_a1, "12345abcde");
	strcpy(memmove_b1, "12345abcde");
	printf("ft_mmove(des: \"12345abcde\" at buf + 5, sou: buf + 0, 10): %s | "
		"memmove(des: \"12345abcde\" at buf + 5, sou: buf + 0, 10): %s\n", 
		(char *)ft_memmove(memmove_a1 + 5, memmove_a1, 10), 
		(char *)memmove(memmove_b1 + 5, memmove_b1, 10));
	strcpy(memmove_a1, "12345abcde");
	strcpy(memmove_b1, "12345abcde");
	printf("ft_mmove(des: \"12345abcde\" at buf + 5, sou: buf + 0, 15): %s | "
		"memmove(des: \"12345abcde\" at buf + 5, sou: buf + 0, 15): %s\n", 
		(char *)ft_memmove(memmove_a1 + 5, memmove_a1, 15), 
		(char *)memmove(memmove_b1 + 5, memmove_b1, 15));

	return (0);
}
*/