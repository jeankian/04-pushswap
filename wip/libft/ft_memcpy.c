/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:08:26 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:08:26 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
*/

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	const char	*sou;
	char		*des;

	sou = s2;
	des = s1;
	while (n > 0)
	{
		*des = *sou;
		des++;
		sou++;
		n--;
	}
	return (s1);
}
/*
int	main(void)
{
	char	memcpy_d1[10] = "hallo"; //destination
	char	memcpy_d2[10] = "hallo"; //destination	
	char	memcpy_s1[10] = "aaaaa"; //source
	printf("ft_memcpy same add as des?: %d | memcpy same add as des?: %d\n", 
		ft_memcpy(memcpy_d1, memcpy_s1, 3) == (void *)memcpy_d1, 
		memcpy(memcpy_d2, memcpy_s1, 3) == (void *)memcpy_d2);
	strcpy(memcpy_d1, "hallo");
	strcpy(memcpy_d2, "hallo");
	strcpy(memcpy_s1, "aaaaa");
	printf("ft_memcpy(des: \"hallo\", sou: \"aaaaa\", 3): %s | "
		"memcpy(des: \"hallo\", sou: \"aaaaa\", 3): %s\n", 
		(char *)ft_memcpy(memcpy_d1, memcpy_s1, 3), 
		(char *)memcpy(memcpy_d2, memcpy_s1, 3));
	strcpy(memcpy_d1, "hallo");
	strcpy(memcpy_d2, "hallo");
	strcpy(memcpy_s1, "aaaaa");
	int		memcpy_n = 0;	
	printf("ft_memcpy(des: \"hallo\", sou: \"aaaaa\", 0): %s | "
		"memcpy(des: \"hallo\", sou: \"aaaaa\", 0): %s\n", 
		(char *)ft_memcpy(memcpy_d1, memcpy_s1, memcpy_n), 
		(char *)memcpy(memcpy_d2, memcpy_s1, memcpy_n));
	strcpy(memcpy_d1, "hallo");
	strcpy(memcpy_d2, "hallo");
	strcpy(memcpy_s1, "aaaaa");
	printf("ft_memcpy(des: \"hallo\", sou: \"aaaaa\", 7): %s | "
		"memcpy(des: \"hallo\", sou: \"aaaaa\", 7): %s\n", 
		(char *)ft_memcpy(memcpy_d1, memcpy_s1, 7), 
		(char *)memcpy(memcpy_d2, memcpy_s1, 7));
	strcpy(memcpy_d1, "hallo");
	strcpy(memcpy_d2, "hallo");
	char	memcpy_s2[10] = "aaaaahhh"; //source
	printf("ft_memcpy(des: \"hallo\", sou: \"aaaaahhh\", 10): %s | "
		"memcpy(des: \"hallo\", sou: \"aaaaahhh\", 10): %s\n", 
		(char *)ft_memcpy(memcpy_d1, memcpy_s2, 10), 
		(char *)memcpy(memcpy_d2, memcpy_s2, 10));

	return (0);
}
*/