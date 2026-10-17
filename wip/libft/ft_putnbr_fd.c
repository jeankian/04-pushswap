/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:09:01 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:09:01 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
/*
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

static int	ncount(int n)
{
	long	i;
	int	ct;

	ct = 1;
	i = n;
	if (i < 0)
		i = -i;
	while (i >= 10)
	{
		i = i / 10;
		ct++;
	}
	if (n < 0)
		ct = ct + 1;
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
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	*c;
	char	*k;

	c = ft_itoa(n);
	if (c == NULL)
		return ;
	k = c;
	while (*c)
		write(fd, c++, 1);
	free(k);
}

/*
int	main(void)
{
	ft_putnbr_fd(0, 1);
	printf("\n");
	ft_putnbr_fd(123, 1);
	printf("\n");
	ft_putnbr_fd(-123, 1);
	printf("\n");
	ft_putnbr_fd(INT_MAX, 1);
	printf("\n");
	ft_putnbr_fd(INT_MIN, 1);
	printf("\n");
	
	return (0);
}
*/
