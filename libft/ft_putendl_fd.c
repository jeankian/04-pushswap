/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:35:29 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/06 17:43:26 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*#include <stdio.h>
int	main(void)
{
	ft_putendl_fd("hello", 1);
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
	ft_putendl_fd("hello", fd);
	close(fd);
}*/