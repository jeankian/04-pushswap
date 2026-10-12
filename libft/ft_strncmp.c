/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:57:01 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/03 12:16:20 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char *s1 = "heli";
	const char *s2 = "hello";

	printf("mine:   %i\n", ft_strncmp(s1, s2, 4));
	printf("actual: %i\n", strncmp(s1, s2, 4));
	printf("mine:   %i\n", ft_strncmp(s1, s2, 0));
	printf("actual: %i", strncmp(s1, s2, 0));
}*/