/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 12:26:47 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/02 14:40:41 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_circularly_sorted(t_stack *stack)
{
	int		count;
	t_stack	*first;

	if (stack == NULL || stack->next == NULL)
		return (true);
	first = stack;
	count = 0;
	while (stack && stack -> next)
	{
		if (stack -> index > stack -> next -> index)
			count++;
		if (count > 1)
			return (false);
		stack = stack -> next;
	}
	if (stack->index > first->index)
		count++;
	if (count > 1)
		return (false);
	return (true);
}

void	move_a_min_to_top(t_total *stacks)
{
	int	min_pos;

	min_pos = find_min_pos(stacks->stack_a);
	move_a_pos_to_top(stacks, min_pos);
}
