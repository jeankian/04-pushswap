/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:10:35 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:10:35 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("ft_tolower('a'): %c | tolower('a'): %c\n", 
		ft_tolower('a'), tolower('a'));
	printf("ft_tolower('Z'): %c | tolower('Z'): %c\n", 
		ft_tolower('Z'), tolower('Z'));
	printf("ft_tolower('!'): %c | tolower('!'): %c\n", 
		ft_tolower('!'), tolower('!'));
	printf("ft_tolower(' '): %c | tolower(' '): %c\n", 
		ft_tolower(' '), tolower(' '));
	printf("ft_tolower('\\n'): %d | tolower('\\n'): %d\n", 
		ft_tolower('\n'), tolower('\n'));
	printf("ft_tolower('0'): %c | tolower('0'): %c\n", 
		ft_tolower('0'), tolower('0'));
	printf("ft_tolower(0): %c | tolower(0): %c\n", 
		ft_tolower(0), tolower(0));
	printf("ft_tolower(12345): %c | tolower(12345): %c\n", 
		ft_tolower(12345), tolower(12345));
	printf("ft_tolower(-1): %c | tolower(-1): %c\n", 
		ft_tolower(-1), tolower(-1));
		
	return (0);
}
*/