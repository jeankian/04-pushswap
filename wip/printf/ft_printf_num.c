/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 17:18:42 by jkian             #+#    #+#             */
/*   Updated: 2026/09/27 17:18:46 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dec_int(int *i, int *ct, va_list *ap)
{
	long	n;
	char	res[10];
	int		r;

	*i = *i + 1;
	n = va_arg(*ap, int);
	if (n == 0)
		ft_putchar('0', ct);
	if (n < 0)
	{
		ft_putchar('-', ct);
		n = -n;
	}
	r = 0;
	while (n != 0)
	{
		res[r] = n % 10 + '0';
		r++;
		n = n / 10;
	}
	while (r > 0)
	{
		r--;
		ft_putchar(res[r], ct);
	}
}

void	ft_undec(int *i, int *ct, va_list *ap)
{
	unsigned int	n;
	char			res[10];
	int				r;

	*i = *i + 1;
	n = va_arg(*ap, unsigned int);
	if (n == 0)
		ft_putchar('0', ct);
	r = 0;
	while (n != 0)
	{
		res[r] = n % 10 + '0';
		r++;
		n = n / 10;
	}
	while (r > 0)
	{
		r--;
		ft_putchar(res[r], ct);
	}
}
