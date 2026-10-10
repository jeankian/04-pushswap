/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 17:47:30 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/03 17:47:46 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//move node to top of B by calculating the move needed for rb or rrb and use the
//one with the least number of moves
//change back to original after testing
void	move_b_pos_to_top(t_total *stacks, int pos)
{
	int	size;
	int	rb_dist;
	int	rrb_dist;

	size = stack_size((&stacks->stack_b));
	rb_dist = pos;
	rrb_dist = size - pos;
	if (rb_dist <= rrb_dist)
	{
		while (rb_dist > 0)
		{
			rotate_b(stacks);
			rb_dist--;
		}
	}
	else
	{
		while (rrb_dist > 0)
		{
			reverse_rotate_b(stacks);
			rrb_dist--;
		}
	}
}

//move node to top of A by calculating the move needed for rb or rrb and use the
//one with the least number of moves
//change back to original after testing
void	move_a_pos_to_top(t_total *stacks, int pos)
{
	int	size;
	int	ra_dist;
	int	rra_dist;

	size = stack_size(&stacks->stack_a);
	ra_dist = pos;
	rra_dist = size - pos;
	if (ra_dist <= rra_dist)
	{
		while (ra_dist > 0)
		{
			rotate_a(stacks);
			ra_dist--;
		}
	}
	else
	{
		while (rra_dist > 0)
		{
			reverse_rotate_a(stacks);
			rra_dist--;
		}
	}
}
