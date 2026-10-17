/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:09:31 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:09:31 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
void	funct(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1;
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "HALLO";
	ft_striteri(str, funct);
	printf("%s\n", str);
		
	return (0);
}
*/