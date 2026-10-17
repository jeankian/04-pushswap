/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:06:04 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:06:04 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("ft_isalpha('a'): %d | isalpha('a'): %d\n", 
		ft_isalpha('a'), isalpha('a'));
	printf("ft_isalpha('Z'): %d | isalpha('Z'): %d\n", 
		ft_isalpha('Z'), isalpha('Z'));
	printf("ft_isalpha('!'): %d | isalpha('!'): %d\n", 
		ft_isalpha('!'), isalpha('!'));
	printf("ft_isalpha(' '): %d | isalpha(' '): %d\n", 
		ft_isalpha(' '), isalpha(' '));
	printf("ft_isalpha('\\n'): %d | isalpha('\\n'): %d\n", 
		ft_isalpha('\n'), isalpha('\n'));
	printf("ft_isalpha('0'): %d | isalpha('0'): %d\n", 
		ft_isalpha('0'), isalpha('0'));
	printf("ft_isalpha(0): %d | isalpha(0): %d\n", 
		ft_isalpha(0), isalpha(0));
	printf("ft_isalpha(12345): %d | isalpha(12345): %d\n", 
		ft_isalpha(12345), isalpha(12345));
	printf("ft_isalpha(-1): %d | isalpha(-1): %d\n", 
		ft_isalpha(-1), isalpha(-1));
		
	return (0);
}
*/