/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:38:18 by xin-jili          #+#    #+#             */
/*   Updated: 2026/09/18 17:54:18 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count = print_specifier(*++format, ap, count);
		else
			count += write(1, format, 1);
		if (*format)
			format++;
	}
	va_end(ap);
	return (count);
}

/*#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	//TEST CASE 1
	printf("=== TEST CASE 1 (char, str, pointer format specifier) ===\n");
	int count;
	int	ptr_variable;

	ptr_variable = 0;
	count = ft_printf("Hello %s, chararcter %c, ptr %p, %%\n", "World", 
		'Z', &ptr_variable);
	printf("%d\n", count);
	
	count = printf("Hello %s, chararcter %c, ptr %p, %%\n", "World", 
		'Z', &ptr_variable);
	printf("%d\n", count);

	ft_printf("\n");

	//TEST CASE 2
	printf("=== TEST CASE 2 (all numbers format specifier) ===\n");
	count = ft_printf("decimal and integer: %d & %i, "
		"unsigned decimal: %u, hexadecimal: %x & %X", 
		-8712683,  -8712683, 98792879, 1208, 1208);
	printf("\n%d\n", count);

	count = printf("decimal and integer: %d & %i, "
		"unsigned decimal: %u, hexadecimal: %x & %X", 
		-8712683,  -8712683, 98792879, 1208, 1208);
	printf("\n%d\n", count);

	ft_printf("\n");

	//TEST CASE 3
	printf("=== TEST CASE 3 (unidentified format specifier) ===\n");
	count = ft_printf("hello world %q");
	printf("\n%d\n", count);

	ft_printf("\n");

	char	*str = "hello %j world";
	count = ft_printf(str, 'd');
	printf("\n%d\n", count);

	count = printf(str, 'd');
	printf("\n%d\n", count);

	ft_printf("\n");

	//TEST CASE 4
	printf("=== TEST CASE 4 (format specifier at the end) ===\n");
	char	*str2 = "hello %c world %";
	count = ft_printf(str2, 'd');
	printf("\n%d\n", count);

	count = printf(str2, 'd');
	printf("\n%d\n", count);
	ft_printf("\n");

	//TEST CASE 5
	printf("=== TEST CASE 5 (extreme numbers) ===\n");
	count = ft_printf("INT_MIN & INT_MAX: %d & %i, "
		 "UINT_MAX: %u, hexadecimal: %x & %X", 
		-2147483648,  2147483647, 4294967295, 74969, 74969);
	printf("\n%d\n", count);

	count = printf("INT_MIN & INT_MAX: %d & %i, "
		"UINT_MAX: %u, hexadecimal: %x & %X", 
		(int)-2147483648,  (int)2147483647, (unsigned int)4294967295, 
		(unsigned int)74969, (unsigned int)74969);
	printf("\n%d\n", count);
	ft_printf("\n");

	//TEST CASE 6
	printf("=== TEST CASE 6 (null checkers) ===\n");
	count = ft_printf("invalid pointer: %p\n", NULL);
	printf("%d\n", count);

	count = printf("invalid pointer: %p\n", NULL);
	printf("%d\n", count);
	ft_printf("\n");

	count = ft_printf("invalid str: %s\n", NULL);
	printf("%d\n", count);
	count = printf("invalid str: %s\n", (char *)NULL);
	printf("%d\n", count);
}*/