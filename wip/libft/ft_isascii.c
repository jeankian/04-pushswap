/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:06:12 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:06:12 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("ft_isascii('a'): %d | isascii('a'): %d\n", 
		ft_isascii('a'), isascii('a'));
	printf("ft_isascii('Z'): %d | isascii('Z'): %d\n", 
		ft_isascii('Z'), isascii('Z'));
	printf("ft_isascii('!'): %d | isascii('!'): %d\n", 
		ft_isascii('!'), isascii('!'));
	printf("ft_isascii(' '): %d | isascii(' '): %d\n", 
		ft_isascii(' '), isascii(' '));
	printf("ft_isascii('\\n'): %d | isascii('\\n'): %d\n", 
		ft_isascii('\n'), isascii('\n'));
	printf("ft_isascii('0'): %d | isascii('0'): %d\n", 
		ft_isascii('0'), isascii('0'));
	printf("ft_isascii(0): %d | isascii(0): %d\n", 
		ft_isascii(0), isascii(0));
	printf("ft_isascii(12345): %d | isascii(12345): %d\n", 
		ft_isascii(12345), isascii(12345));
	printf("ft_isascii(-1): %d | isascii(-1): %d\n", 
		ft_isascii(-1), isascii(-1));
		
	return (0);
}
*/