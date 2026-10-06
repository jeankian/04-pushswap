/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:47:55 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:47:56 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	fill_digits(int len, long nb, char *res)
{
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		nb *= -1;
		res[0] = '-';
	}
	while (nb > 0)
	{
		res[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*res;

	nb = n;
	len = count_digits(n);
	res = malloc(sizeof (char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	len --;
	fill_digits(len, nb, res);
	return (res);
}
