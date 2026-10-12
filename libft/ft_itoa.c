/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:57:57 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/24 18:00:02 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_count(long n)
{
	size_t	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	count;
	size_t	i;

	i = 0;
	nb = (long) n;
	count = int_count(nb);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		i++;
		nb = -nb;
	}
	str[count] = '\0';
	while (count-- > i)
	{
		str[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char	*s = ft_itoa(-2147483648);
	printf("%s", s);
	free(s);
}*/