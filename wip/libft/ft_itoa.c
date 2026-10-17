/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:06:53 by jkian             #+#    #+#             */
/*   Updated: 2026/08/23 19:37:49 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
*/

static int	ncount(int n)
{
	long	i;
	int		ct;

	i = n;
	ct = 1;
	if (i < 0)
	{
		i = -i;
		ct++;
	}
	while (i >= 10)
	{
		i = i / 10;
		ct++;
	}
	return (ct);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	i;
	long	ct;

	ct = ncount(n);
	str = malloc((ct + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = n;
	if (n < 0)
	{
		str[0] = '-';
		i = -i;
	}
	str[ct] = '\0';
	if (n == 0)
		str[0] = '0';
	while (i != 0)
	{
		ct--;
		str[ct] = i % 10 + '0';
		i = i / 10;
	}
	return (str);
}

/*
int	main(void)
{
	printf("ft_itoa(0): %s\n", ft_itoa(0));
	printf("ft_itoa(123): %s\n", ft_itoa(123));
	printf("ft_itoa(-123): %s\n", ft_itoa(-123));
	printf("ft_itoa(INT_MAX): %s\n", ft_itoa(INT_MAX));
	printf("ft_itoa(INT_MIN): %s\n", ft_itoa(INT_MIN));

	return (0);
}
*/
