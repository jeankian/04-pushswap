/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 00:06:58 by jkian             #+#    #+#             */
/*   Updated: 2026/09/27 15:20:06 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(const char *a, int *i, int *ct, va_list *ap)
{
	*i = *i + 1;
	if (a[*i] == '%')
		ft_putchar(a[(*i)++], ct);
	else if (a[*i] == 'c')
		ft_char(i, ct, ap);
	else if (a[*i] == 's')
		ft_str(i, ct, ap);
	else if (a[*i] == 'p')
		ft_voidptr(i, ct, ap);
	else if (a[*i] == 'd' || a[*i] == 'i')
		ft_dec_int(i, ct, ap);
	else if (a[*i] == 'u')
		ft_undec(i, ct, ap);
	else if (a[*i] == 'x')
		ft_hexlo(i, ct, ap);
	else if (a[*i] == 'X')
		ft_hexup(i, ct, ap);
	else
	{
		ft_putchar('%', ct);
		return (0);
	}
	return (1);
}

int	ft_printf(const char *a, ...)
{
	va_list	ap;
	int		ct;
	int		i;

	ct = 0;
	i = 0;
	va_start(ap, a);
	while (a[i] != '\0')
	{
		if (a[i] == '%' && a[i + 1] != '\0')
		{
			if (!ft_check(a, &i, &ct, &ap))
			{
				ft_putchar(a[i], &ct);
				i++;
			}
		}
		else
		{
			ft_putchar(a[i], &ct);
			i++;
		}
	}
	va_end(ap);
	return (ct);
}
/*
#include "ft_printf.h"

#include <stdio.h>
#include <limits.h>

void	check_char(char *format, char c)
{
	int	a;
	int	b;

	a = ft_printf(format, c);
	printf("\n");

	b = printf(format, c);
	printf("\n");

	if (a != b)
		printf("MISMATCHED: ft=%d | sys=%d\n", a, b);
	else
		printf("matched: ft=%d | sys=%d\n", a, b);
}

void	check_str(char *format, char *str)
{
	int	a;
	int	b;

	a = ft_printf(format, str);
	printf("\n");

	b = printf(format, str);
	printf("\n");

	if (a != b)
		printf("MISMATCHED: ft=%d | sys=%d\n", a, b);
	else
		printf("matched: ft=%d | sys=%d\n", a, b);
}

void	check_voidptr(char *format, void *str)
{
	int	a;
	int	b;

	a = ft_printf(format, str);
	printf("\n");

	b = printf(format, str);
	printf("\n");

	if (a != b)
		printf("MISMATCHED: ft=%d | sys=%d\n", a, b);
	else
		printf("matched: ft=%d | sys=%d\n", a, b);
}

void	check_dec_int(char *format, int i)
{
	int	a;
	int	b;

	a = ft_printf(format, i);
	printf("\n");

	b = printf(format, i);
	printf("\n");

	if (a != b)
		printf("MISMATCHED: ft=%d | sys=%d\n", a, b);
	else
		printf("matched: ft=%d | sys=%d\n", a, b);
}

void	check_undec_hex(char *format, unsigned int i)
{
	int	a;
	int	b;

	a = ft_printf(format, i);
	printf("\n");

	b = printf(format, i);
	printf("\n");

	if (a != b)
		printf("MISMATCHED: ft=%d | sys=%d\n", a, b);
	else
		printf("matched: ft=%d | sys=%d\n", a, b);
}

void	check_others(char *format)
{
	int	a;
	int	b;

	a = ft_printf("%s", format);
	printf("\n");

	b = printf("%s", format);
	printf("\n");

	if (a != b)
		printf("MISMATCHED: ft=%d | sys=%d\n", a, b);
	else
		printf("matched: ft=%d | sys=%d\n", a, b);
}

int	main(void)
{
	printf("!!! TEST FORMAT: %%c\n");
	check_char("%c", 'a');
	check_char("%c", 'A');
	check_char("%c", ' ');
	check_char("%c", 0);
	check_char("%c", '0');
	printf("\n");

	printf("!!! TEST FORMAT: %%s\n");
	check_str("%s", "Hello, World!");
	check_str("%s", "");
	check_str("%s", "NULL");
	check_str("%s", "0123");
	printf("\n");

	printf("!!! TEST FORMAT: %%p\n");
	check_voidptr("%p", NULL);
	int x = 42;
	check_voidptr("%p", &x);
	printf("\n");

	printf("!!! TEST FORMAT: %%d\n");
	check_dec_int("%d", 42);
	check_dec_int("%d", -42);
	check_dec_int("%d", 0);
	check_dec_int("%d", INT_MAX);
	check_dec_int("%d", INT_MIN);
	printf("\n");

	printf("!!! TEST FORMAT: %%i\n");
	check_dec_int("%i", 42);
	check_dec_int("%i", -42);
	check_dec_int("%i", 0);
	check_dec_int("%i", INT_MAX);
	check_dec_int("%i", INT_MIN);
	printf("\n");

	printf("!!! TEST FORMAT: %%u\n");
	check_undec_hex("%u", 42);
	check_undec_hex("%u", 0);
	check_undec_hex("%u", UINT_MAX);
	check_undec_hex("%u", -1);
	printf("\n");
	
	printf("!!! TEST FORMAT: %%x\n");
	check_undec_hex("%x", 0);
	check_undec_hex("%x", 10);
	check_undec_hex("%x", -1);
	printf("\n");

	printf("!!! TEST FORMAT: %%X\n");
	check_undec_hex("%X", 0);
	check_undec_hex("%X", 10);
	check_undec_hex("%X", -1);
	printf("\n");	

	printf("!!! TEST FORMAT: misc\n");
	check_others("%%");
	check_others("%%%%");
	check_others("text text text");
	check_others("text%");
	check_others("text %z text");
	check_others("");
	printf("\n");

	return (0);
}
*/
