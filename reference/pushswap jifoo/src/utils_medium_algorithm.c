/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium_algorithm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 13:54:12 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/03 17:43:00 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rb_stack(int rb_dist, t_total *stacks, int i)
{
	int	staggered;

	staggered = 0;
	while (rb_dist > 0)
	{
		rotate_b(stacks);
		rb_dist--;
		if ((stacks->stack_b)->index == (i - 1))
		{
			push_a(stacks);
			staggered = 1;
			rb_dist--;
		}
	}
	push_a(stacks);
	if (staggered == 1)
		swap_a(stacks);
}

static void	rrb_stack(int rrb_dist, t_total *stacks, int i)
{
	int	staggered;

	staggered = 0;
	while (rrb_dist > 0)
	{
		reverse_rotate_b(stacks);
		rrb_dist--;
		if ((stacks->stack_b)->index == (i - 1))
		{
			push_a(stacks);
			staggered = 1;
		}
	}
	push_a(stacks);
	if (staggered == 1)
		swap_a(stacks);
}

void	btoamod(t_total *stacks, int pos, int i)
{
	int	size;
	int	rb_dist;
	int	rrb_dist;

	size = stack_size(&stacks->stack_b);
	rb_dist = pos;
	rrb_dist = size - pos;
	if (rb_dist <= rrb_dist)
		rb_stack(rb_dist, stacks, i);
	else
		rrb_stack(rrb_dist, stacks, i);
}
