/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:19:38 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/06 17:19:41 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <stdio.h>
int	main(void)
{
	ft_putchar_fd('h', 1);
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
	ft_putchar_fd('h', fd);
	close(fd);
}*/