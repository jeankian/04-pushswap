/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 22:00:00 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/07 14:27:52 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	benchmark_mode(t_total *stacks, t_algo algorithm)
{
	print_disorder(stacks->disorder);
	print_strategy(stacks->disorder, algorithm);
	ft_putstr_fd("[bench] ", 2);
	print_metric_inline("total_ops", stacks->moves.total);
	ft_putchar_fd('\n', 2);
	print_operations(&stacks->moves);
}
