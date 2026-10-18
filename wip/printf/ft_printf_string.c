/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 17:18:24 by jkian             #+#    #+#             */
/*   Updated: 2026/09/27 17:18:30 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stddef.h>

void	ft_char(int *i, int *ct, va_list *ap)
{
	int		c;

	*i = *i + 1;
	c = va_arg(*ap, int);
	ft_putchar(c, ct);
}

void	ft_str(int *i, int *ct, va_list *ap)
{
	int		si;
	char	*str;

	*i = *i + 1;
	si = 0;
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)", ct);
	}
	else
	{
		while (str[si])
		{
			ft_putchar(str[si], ct);
			si++;
		}
	}
}
