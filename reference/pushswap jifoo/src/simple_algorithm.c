/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:16:45 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 17:41:49 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//insertion sort adaptation
void	simple_algorithm(t_total *stacks)
{
	int	x;
	int	target_pos;
	int	max_pos;

	if (sort_checker(stacks))
		return ;
	while (stacks->stack_a != NULL)
	{
		if (stacks->stack_b == NULL)
			push_b(stacks);
		else
		{
			x = stacks->stack_a->index;
			target_pos = find_target_pos(stacks->stack_b, x);
			move_b_pos_to_top(stacks, target_pos);
			push_b(stacks);
		}
	}
	max_pos = find_max_pos(stacks->stack_b);
	move_b_pos_to_top(stacks, max_pos);
	while (stacks->stack_b != NULL)
	{
		push_a(stacks);
	}
}
