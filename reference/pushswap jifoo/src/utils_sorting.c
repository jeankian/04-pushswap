/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 20:59:53 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/03 17:48:23 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//count how many nodes in a stack
int	stack_size(t_stack **stack)
{
	int		count;
	t_stack	*current;

	if (!stack)
		return (0);
	count = 0;
	current = *stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

//return position of the node with the largest index
int	find_max_pos(t_stack *stack)
{
	int		max_index;
	int		current_pos;
	int		max_pos;

	max_index = -1;
	current_pos = 0;
	max_pos = 0;
	while (stack != NULL)
	{
		if (stack-> index > max_index)
		{
			max_index = stack-> index;
			max_pos = current_pos;
		}
		current_pos++;
		stack = stack-> next;
	}
	return (max_pos);
}

//return position of the node with the smallest index
int	find_min_pos(t_stack *stack)
{
	int		min_index;
	int		current_pos;
	int		min_pos;

	min_index = stack -> index;
	current_pos = 0;
	min_pos = 0;
	while (stack != NULL)
	{
		if (stack-> index < min_index)
		{
			min_index = stack-> index;
			min_pos = current_pos;
		}
		current_pos++;
		stack = stack-> next;
	}
	return (min_pos);
}

//find the B node that should come immediately after the current A top node
//which is the largest node smaller than the current A top node
int	find_target_pos(t_stack *stack_b, int x)
{
	t_stack	*current;
	int		current_pos;
	int		best_smaller_index;
	int		best_smaller_pos;

	current = stack_b;
	current_pos = 0;
	best_smaller_index = -1;
	best_smaller_pos = -1;
	while (current != NULL)
	{
		if (current -> index < x && current -> index > best_smaller_index)
		{
			best_smaller_index = current -> index;
			best_smaller_pos = current_pos;
		}
		current = current -> next;
		current_pos++;
	}
	if (best_smaller_pos == -1)
		return (find_max_pos(stack_b));
	return (best_smaller_pos);
}

int	find_target_pos_2(t_stack *stack_a, int x)
{
	t_stack	*current;
	int		current_pos;
	int		best_greater_index;
	int		best_greater_pos;

	current = stack_a;
	current_pos = 0;
	best_greater_index = INT_MAX;
	best_greater_pos = -1;
	while (current != NULL)
	{
		if (current -> index > x && current -> index < best_greater_index)
		{
			best_greater_index = current -> index;
			best_greater_pos = current_pos;
		}
		current = current -> next;
		current_pos++;
	}
	if (best_greater_pos == -1)
		return (find_min_pos(stack_a));
	return (best_greater_pos);
}
