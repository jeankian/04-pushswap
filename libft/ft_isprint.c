/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:03:46 by xin-jili          #+#    #+#             */
/*   Updated: 2026/07/28 13:16:06 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*#include <stdio.h>
int	main(void)
{
	int	c;

	c = 0;
	while (c <= 127)
	{
		if (ft_isprint(c))
			printf("character is printable: %c\n", c);
		else
			printf("character is not printable: %c\n", c);
		c++;
	}
	return (0);
}*/
