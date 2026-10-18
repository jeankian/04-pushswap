/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 17:19:00 by jkian             #+#    #+#             */
/*   Updated: 2026/09/27 17:19:04 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

void	ft_putchar(char c, int *ct)
{
	write(1, &c, 1);
	*ct = *ct + 1;
}

void	ft_putstr(char *s, int *ct)
{
	int	d;

	d = 0;
	while (s[d])
	{
		write(1, &s[d], 1);
		d++;
		*ct = *ct + 1;
	}
}
