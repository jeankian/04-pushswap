/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:09:53 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:09:53 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stddef.h>

#include <stdio.h>
#include <string.h>
*/

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}
/*
int	main(void)
{
	printf("ft_strlen(\"hallo\"): %zu | strlen(\"hallo\"): %zu\n", 
		ft_strlen("hallo"), strlen("hallo"));
	printf("ft_strlen(\"\"): %zu | strlen(\"\"): %zu\n", 
		ft_strlen(""), strlen(""));

	return (0);
}
*/