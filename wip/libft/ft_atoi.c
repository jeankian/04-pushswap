/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:05:08 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:05:08 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stdio.h>
#include <stdlib.h>
*/

int	ft_atoi(const char *str)
{
	int	n;
	int	res;

	n = 1;
	res = 0;
	while ((*str >= '\t' && *str <= '\r') || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -n;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * n);
}
/*
int	main(void)
{
	printf("ft_atoi(\"\"): %d | atoi(\"\"): %d\n", ft_atoi(""), atoi(""));
	printf("ft_atoi(\"0\"): %d | atoi(\"0\"): %d\n", ft_atoi("0"), atoi("0"));
	printf("ft_atoi(\"123\"): %d | atoi(\"123\"): %d\n", 
		ft_atoi("123"), atoi("123"));
	printf("ft_atoi(\"-123\"): %d | atoi(\"-123\"): %d\n", 
		ft_atoi("-123"), atoi("-123"));
	printf("ft_atoi(\"  123\"): %d | atoi(\"  123\"): %d\n", 
		ft_atoi("  123"), atoi("  123"));
	printf("ft_atoi(\"  -123\"): %d | atoi(\"  -123\"): %d\n", 
		ft_atoi("  -123"), atoi("  -123"));
	printf("ft_atoi(\"  -+123\"): %d | atoi(\"  -+123\"): %d\n", 
		ft_atoi("  -+123"), atoi("  -+123"));
	printf("ft_atoi(\"  -- 123\"): %d | atoi(\"  -- 123\"): %d\n", 
		ft_atoi("  -- 123"), atoi("  -- 123"));
	printf("ft_atoi(\"  + ! -123\"): %d | atoi(\"  + ! -123\"): %d\n", 
		ft_atoi("  + ! -123"), atoi("  + ! -123"));
	printf("ft_atoi(\"  -+-abc123\"): %d | atoi(\"  -+-abc123\"): %d\n", 
		ft_atoi("  -+-abc123"), atoi("  -+-abc123")); 
	printf("ft_atoi(\"  -123abc\"): %d | atoi(\"  -123abc\"): %d\n", 
		ft_atoi("  -123abc"), atoi("  -123abc"));

	return (0);
}
*/