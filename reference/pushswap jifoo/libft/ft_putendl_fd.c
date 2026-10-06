/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:50:22 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:50:23 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;
	char			newline;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	newline = '\n';
	write(fd, &newline, 1);
}
