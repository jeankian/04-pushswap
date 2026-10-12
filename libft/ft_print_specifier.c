/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 14:41:41 by xin-jili          #+#    #+#             */
/*   Updated: 2026/09/18 14:41:43 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_specifier(char specifier, va_list ap, int count)
{
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_int(va_arg(ap, int));
	else if (specifier == 'u')
		count += print_unsigned(va_arg(ap, unsigned int), 'u');
	else if (specifier == 'x')
		count += print_unsigned(va_arg(ap, unsigned int), 'x');
	else if (specifier == 'X')
		count += print_unsigned(va_arg(ap, unsigned int), 'X');
	else if (specifier == '%')
		count += print_char('%');
	else if (specifier == '\0')
		count = -1;
	else
		count += print_char('%');
	return (count);
}
