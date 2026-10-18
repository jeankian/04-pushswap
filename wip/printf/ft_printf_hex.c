/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 17:17:48 by jkian             #+#    #+#             */
/*   Updated: 2026/09/27 17:18:04 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	return (hex[c]);
}

void	ft_voidptr(int *i, int *ct, va_list *ap)
{
	unsigned long	n;
	char			remainder[16];
	int				r;

	*i = *i + 1;
	n = (unsigned long)va_arg(*ap, void *);
	if (n == 0)
		ft_putstr("(nil)", ct);
	else
	{
		ft_putstr("0x", ct);
		r = 0;
		while (n != 0)
		{
			remainder[r] = n % 16;
			remainder[r] = ft_hex(remainder[r]);
			r++;
			n = n / 16;
		}
		while (r > 0)
		{
			r--;
			ft_putchar(remainder[r], ct);
		}
	}
}

void	ft_hexlo(int *i, int *ct, va_list *ap)
{
	unsigned int		n;
	int					r;
	char				remainder[16];

	*i = *i + 1;
	n = va_arg(*ap, int);
	if (n == 0)
		ft_putchar('0', ct);
	r = 0;
	while (n != 0)
	{
		remainder[r] = n % 16;
		remainder[r] = ft_hex(remainder[r]);
		r++;
		n = n / 16;
	}
	while (r > 0)
	{
		r--;
		ft_putchar(remainder[r], ct);
	}
}

void	ft_hexup(int *i, int *ct, va_list *ap)
{
	unsigned int		n;
	int					r;
	char				remainder[16];

	*i = *i + 1;
	n = va_arg(*ap, int);
	if (n == 0)
		ft_putchar('0', ct);
	r = 0;
	while (n != 0)
	{
		remainder[r] = n % 16;
		remainder[r] = ft_hex(remainder[r]);
		if (remainder[r] >= 'a' && remainder[r] <= 'z')
			remainder[r] = remainder[r] - ('a' - 'A');
		r++;
		n = n / 16;
	}
	while (r > 0)
	{
		r--;
		ft_putchar(remainder[r], ct);
	}
}
