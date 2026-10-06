/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_number_algorithm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 17:30:45 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 17:45:01 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_sorted(t_stack *stack)
{
	while (stack != NULL && stack -> next != NULL)
	{
		if (stack -> index > stack -> next -> index)
			return (false);
		stack = stack -> next;
	}
	return (true);
}

static void	sort_two(t_total *stacks)
{
	if ((stacks->stack_a)-> index > (stacks->stack_a)-> next -> index)
	{
		swap_a(stacks);
	}
}

void	sort_three(t_total *stacks)
{
	int	max_pos;

	max_pos = find_max_pos(stacks->stack_a);
	if (max_pos == 0)
	{
		rotate_a(stacks);
	}
	else if (max_pos == 1)
	{
		reverse_rotate_a(stacks);
	}
	if ((stacks->stack_a)-> index > (stacks->stack_a)-> next -> index)
	{
		swap_a(stacks);
	}
}

static void	sort_four_five(t_total *stacks)
{
	int	size;
	int	min_pos;

	size = stack_size(&stacks->stack_a);
	while (size > 3)
	{
		min_pos = find_min_pos(stacks->stack_a);
		move_a_pos_to_top(stacks, min_pos);
		push_b(stacks);
		size--;
	}
	sort_three(stacks);
	while (stacks->stack_b != NULL)
	{
		push_a(stacks);
	}
}

bool	sort_checker(t_total *stacks)
{
	int	size;

	size = stack_size(&stacks->stack_a);
	if (is_sorted(stacks->stack_a))
		return (true);
	if (size == 2)
		sort_two(stacks);
	else if (size == 3)
		sort_three(stacks);
	else if (size <= 5)
		sort_four_five(stacks);
	else if (is_circularly_sorted(stacks->stack_a))
		move_a_min_to_top(stacks);
	else
		return (false);
	return (true);
}
