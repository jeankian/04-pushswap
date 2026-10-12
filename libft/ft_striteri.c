/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:24:16 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/06 12:13:33 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	even_str_lower(unsigned int i, char *s)
{
	if (((i + 1) % 2) == 0)
	{
		if (*s >= 'A' && *s <= 'Z')
		 	*s += 32;
	}
}

#include <stdio.h>
int	main(void)
{
	char	s[] = "EVeN nUMbER";
	printf("before: %s\n", s);
	ft_striteri(s, &even_str_lower);
	printf("after:  %s\n", s);
}*/
