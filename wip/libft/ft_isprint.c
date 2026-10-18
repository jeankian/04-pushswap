/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:06:40 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:06:40 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("ft_isprint('a'): %d | isprint('a'): %d\n", 
		ft_isprint('a'), isprint('a'));
	printf("ft_isprint('Z'): %d | isprint('Z'): %d\n", 
		ft_isprint('Z'), isprint('Z'));
	printf("ft_isprint('!'): %d | isprint('!'): %d\n", 
		ft_isprint('!'), isprint('!'));
	printf("ft_isprint(' '): %d | isprint(' '): %d\n", 
		ft_isprint(' '), isprint(' '));
	printf("ft_isprint('\\n'): %d | isprint('\\n'): %d\n", 
		ft_isprint('\n'), isprint('\n'));
	printf("ft_isprint('0'): %d | isprint('0'): %d\n", 
		ft_isprint('0'), isprint('0'));
	printf("ft_isprint(0): %d | isprint(0): %d\n", 
		ft_isprint(0), isprint(0));
	printf("ft_isprint(12345): %d | isprint(12345): %d\n", 
		ft_isprint(12345), isprint(12345));
	printf("ft_isprint(-1): %d | isprint(-1): %d\n", 
		ft_isprint(-1), isprint(-1));
		
	return (0);
}
*/