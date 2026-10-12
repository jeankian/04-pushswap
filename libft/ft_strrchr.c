/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:34:10 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/30 14:54:49 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*temp;

	if (!s)
		return (NULL);
	p = (char *) s;
	temp = NULL;
	while (*p)
	{
		if (*p == (char)c)
			temp = p;
		p++;
	}
	if ((char)c == '\0')
		temp = p;
	return (temp);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char *s1 = "help me! pleaseeee";
	const char *s2 = "help me! pleaseeee";
	int	c = 'l';

	printf("mine  : %s\n", ft_strrchr(s1, c));
	printf("actual: %s\n", strrchr(s2, c));
}*/

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char *s1 = "bonjour";
	const char *s2 = "bonjour";
	int	c = 's';

	printf("mine  : %s\n", ft_strrchr(s1 + 2, c));
	printf("actual: %s\n", strrchr(s2 + 2, c));
}*/

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char s[] = "tripouille";
	int	c = 't' + 256;

	printf("mine  : %s\n", ft_strrchr(s, c));
	printf("actual: %s\n", strrchr(s, c));
}*/