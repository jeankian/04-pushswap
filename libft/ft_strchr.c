/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:06:27 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/27 11:53:52 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if ((char)c == '\0')
		return (p);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char *s1 = "help me! pleaseeee";
	const char *s2 = "help me! pleaseeee";
	int	c = 'e';

	printf("mine  : %s\n", ft_strchr(s1, c));
	printf("actual: %s\n", strchr(s2, c));
}*/

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s[] = "tripouille";
	int	c = 't' + 256;

	printf("mine  : %s\n", ft_strchr(s, c));
	printf("actual: %s\n", strchr(s, c));
}*/