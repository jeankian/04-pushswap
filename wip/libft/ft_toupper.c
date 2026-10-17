/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:10:40 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:10:40 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("ft_toupper('a'): %c | toupper('a'): %c\n", 
		ft_toupper('a'), toupper('a'));
	printf("ft_toupper('Z'): %c | toupper('Z'): %c\n", 
		ft_toupper('Z'), toupper('Z'));
	printf("ft_toupper('!'): %c | toupper('!'): %c\n", 
		ft_toupper('!'), toupper('!'));
	printf("ft_toupper(' '): %c | toupper(' '): %c\n", 
		ft_toupper(' '), toupper(' '));
	printf("ft_toupper('\\n'): %d | toupper('\\n'): %d\n", 
		ft_toupper('\n'), toupper('\n'));
	printf("ft_toupper('0'): %c | toupper('0'): %c\n", 
		ft_toupper('0'), toupper('0'));
	printf("ft_toupper(0): %c | toupper(0): %c\n", 
		ft_toupper(0), toupper(0));
	printf("ft_toupper(12345): %c | toupper(12345): %c\n", 
		ft_toupper(12345), toupper(12345));
	printf("ft_toupper(-1): %c | toupper(-1): %c\n", 
		ft_toupper(-1), toupper(-1));
		
	return (0);
}
*/