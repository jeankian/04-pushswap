/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_benchmark_mode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:09:25 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 17:40:35 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_metric_inline(char *name, int value)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(value, 2);
}

void	print_operations(t_moves *moves)
{
	ft_putstr_fd("[bench] ", 2);
	print_metric_inline("sa", moves->sa);
	ft_putchar_fd(' ', 2);
	print_metric_inline("sb", moves->sb);
	ft_putchar_fd(' ', 2);
	print_metric_inline("ss", moves->ss);
	ft_putchar_fd(' ', 2);
	print_metric_inline("pa", moves->pa);
	ft_putchar_fd(' ', 2);
	print_metric_inline("pb", moves->pb);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_metric_inline("ra", moves->ra);
	ft_putchar_fd(' ', 2);
	print_metric_inline("rb", moves->rb);
	ft_putchar_fd(' ', 2);
	print_metric_inline("rr", moves->rr);
	ft_putchar_fd(' ', 2);
	print_metric_inline("rra", moves->rra);
	ft_putchar_fd(' ', 2);
	print_metric_inline("rrb", moves->rrb);
	ft_putchar_fd(' ', 2);
	print_metric_inline("rrr", moves->rrr);
	ft_putchar_fd('\n', 2);
}

void	print_strategy(float disorder, t_algo algorithm)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (algorithm == ALGO_SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (algorithm == ALGO_MEDIUM)
		ft_putstr_fd("Medium / O(n * sqrt(n))\n", 2);
	else if (algorithm == ALGO_COMPLEX)
		ft_putstr_fd("Complex / O(n log(n))\n", 2);
	else if (algorithm == ALGO_ADAPTIVE)
	{
		if (disorder < 0.2)
			ft_putstr_fd("Adaptive / O(n^2)\n", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("Adaptive / O(n * sqrt(n))\n", 2);
		else
			ft_putstr_fd("Adaptive / O(n log(n))\n", 2);
	}
}

static void	print_int(long long nb)
{
	char	c;

	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		print_int((nb / 10));
	c = (nb % 10) + '0';
	write(2, &c, 1);
}

void	print_disorder(float disorder)
{
	long long	int_part;
	float		frac_part;

	ft_putstr_fd("[bench] disorder: ", 2);
	int_part = (long long)(disorder * 100);
	print_int(int_part);
	ft_putchar_fd('.', 2);
	frac_part = (disorder * 100) - int_part;
	frac_part *= 100;
	print_int((long long) frac_part);
	ft_putstr_fd("%\n", 2);
}
