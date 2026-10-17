/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:06:20 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:06:20 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("ft_isdigit('a'): %d | isdigit('a'): %d\n", 
		ft_isdigit('a'), isdigit('a'));
	printf("ft_isdigit('Z'): %d | isdigit('Z'): %d\n", 
		ft_isdigit('Z'), isdigit('Z'));
	printf("ft_isdigit('!'): %d | isdigit('!'): %d\n", 
		ft_isdigit('!'), isdigit('!'));
	printf("ft_isdigit(' '): %d | isdigit(' '): %d\n", 
		ft_isdigit(' '), isdigit(' '));
	printf("ft_isdigit('\\n'): %d | isdigit('\\n'): %d\n", 
		ft_isdigit('\n'), isdigit('\n'));
	printf("ft_isdigit('0'): %d | isdigit('0'): %d\n", 
		ft_isdigit('0'), isdigit('0'));
	printf("ft_isdigit(0): %d | isdigit(0): %d\n", 
		ft_isdigit(0), isdigit(0));
	printf("ft_isdigit(12345): %d | isdigit(12345): %d\n", 
		ft_isdigit(12345), isdigit(12345));
	printf("ft_isdigit(-1): %d | isdigit(-1): %d\n", 
		ft_isdigit(-1), isdigit(-1));
	
	return (0);
}
*/