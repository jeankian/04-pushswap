/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:32:54 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/11 15:02:02 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c <= 127 && c >= 0);
}

/*#include <stdio.h>
int	main(void)
{
	int	c;

	c = 120;
	while (c <= 130)
	{
		if (ft_isascii(c))
			printf("The character is %c\n", c);
		else
			printf("Not an ascii character: %c \n", c);
		c++;
	}
	return (0);
}*/