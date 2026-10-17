/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:05:32 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:05:32 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
//cc ft_strlcat.c -lbsd
*/

void	ft_bzero(void *s, size_t n)
{
	char	*start;
	size_t	i;

	start = s;
	i = 0;
	while (i < n)
	{
		start[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	unsigned char	bzero_a1[5] = {'h', 'a', 'l', 'l', 'o'};
	unsigned char	bzero_a2[5] = {'h', 'a', 'l', 'l', 'o'};
	ft_bzero(bzero_a1, 0);
	bzero(bzero_a2, 0);
	size_t	bzero_i = 0;

	while (bzero_i < sizeof(bzero_a1))
	{
		printf("ft_bzero: %d | bzero: %d\n", 
			bzero_a1[bzero_i], bzero_a2[bzero_i]);
		bzero_i++;
	}
	
	return (0);
}
*/
