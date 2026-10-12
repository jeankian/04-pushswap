/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:55:45 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/06 17:29:06 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

/*#include <stdio.h>
int	main(void)
{
	ft_putstr_fd("hello", 1);
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
	ft_putstr_fd("hello", fd);
	close(fd);
}*/