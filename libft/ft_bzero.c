/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:19:19 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/24 11:32:04 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	if (!s)
		return ;
	p = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

//#include <stdio.h>
//#include <strings.h>
//test for string
/*int	main(void)
{
	char s[] = "hello world";

	ft_bzero(s, 3);
	printf("%s", s);

	return (0);
}*/

//test for int array
/*int	main(void)
{
	int s[] = {3, 2, 0, 5};
	int	i;

	ft_bzero(s, sizeof(int) * 3);
	//bzero(s, sizeof(int) * 3);
	i = 0;
	while (i < 4)
		printf("%i", s[i++]);
	return (0);
}*/