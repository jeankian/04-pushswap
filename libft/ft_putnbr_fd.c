/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:48:09 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/06 17:58:48 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		n = n + '0';
		ft_putchar_fd(n, fd);
	}
}

/*#include <stdio.h>
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}*/

//create test file
/*#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("test", O_RDWR | O_CREAT, 0777);
	if (fd == -1)
		return (1);
	ft_putnbr_fd(-21478, fd);
	close(fd);
}*/