/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:37:59 by xin-jili          #+#    #+#             */
/*   Updated: 2026/09/10 13:38:01 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nbr(unsigned long nb, int base, char *base_symbols)
{
	int	count;

	count = 0;
	if (nb >= (unsigned long)base)
	{
		count += print_nbr(nb / base, base, base_symbols);
		count += print_nbr(nb % base, base, base_symbols);
	}
	else
		count += print_char(base_symbols[nb]);
	return (count);
}

int	print_int(int nb)
{
	int		count;

	count = 0;
	if (nb == -2147483648)
		return (print_str("-2147483648"));
	if (nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	return (count + print_nbr(nb, 10, "0123456789"));
}

int	print_unsigned(unsigned int nb, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'u')
		count += print_nbr(nb, 10, "0123456789");
	else if (specifier == 'x')
		count += print_nbr(nb, 16, "0123456789abcdef");
	else if (specifier == 'X')
		count += print_nbr(nb, 16, "0123456789ABCDEF");
	return (count);
}

int	print_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (print_str("(nil)"));
	count += print_str("0x");
	return (count + print_nbr((unsigned long)ptr, 16, "0123456789abcdef"));
}
