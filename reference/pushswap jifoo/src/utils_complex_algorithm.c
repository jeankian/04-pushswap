/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complex_algorithm.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:34:48 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 17:44:30 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate rotation cost to bring node to the top. 
//+ve value indicates node is at the top half of the stack
//and vice versa. r for +ve & rr for -ve
int	rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (-(size - pos));
}

int	combined_rotation_cost(int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a <= 0 && cost_b <= 0)
	{
		if (-cost_a > -cost_b)
			return (-cost_a);
		return (-cost_b);
	}
	return (abs(cost_a) + abs(cost_b));
}

void	rotate_stack_b(t_total *stacks, int cost)
{
	while (cost > 0)
	{
		rotate_b(stacks);
		cost--;
	}
	while (cost < 0)
	{
		reverse_rotate_b(stacks);
		cost++;
	}
}

void	rotate_stack_a(t_total *stacks, int cost)
{
	while (cost > 0)
	{
		rotate_a(stacks);
		cost--;
	}
	while (cost < 0)
	{
		reverse_rotate_a(stacks);
		cost++;
	}
}
