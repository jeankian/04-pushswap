/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:05:57 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:05:57 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("ft_isalnum('a'): %d | isalnum('a'): %d\n", 
		ft_isalnum('a'), isalnum('a'));
	printf("ft_isalnum('Z'): %d | isalnum('Z'): %d\n", 
		ft_isalnum('Z'), isalnum('Z'));
	printf("ft_isalnum('!'): %d | isalnum('!'): %d\n", 
		ft_isalnum('!'), isalnum('!'));
	printf("ft_isalnum(' '): %d | isalnum(' '): %d\n", 
		ft_isalnum(' '), isalnum(' '));
	printf("ft_isalnum('\\n'): %d | isalnum('\\n'): %d\n", 
		ft_isalnum('\n'), isalnum('\n'));
	printf("ft_isalnum('0'): %d | isalnum('0'): %d\n", 
		ft_isalnum('0'), isalnum('0'));
	printf("ft_isalnum(0): %d | isalnum(0): %d\n", ft_isalnum(0), isalnum(0));
	printf("ft_isalnum(12345): %d | isalnum(12345): %d\n", 
		ft_isalnum(12345), isalnum(12345));
	printf("ft_isalnum(-1): %d | isalnum(-1): %d\n", 
		ft_isalnum(-1), isalnum(-1));
	
	return (0);
}
*/