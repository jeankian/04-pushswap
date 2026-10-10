/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:28:47 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/03 17:46:22 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	set_chunk_size(int arr_count)
{
	long	chunk_size;

	if (arr_count <= 100)
		chunk_size = 15;
	else if (arr_count <= 500)
		chunk_size = arr_count / 11;
	else
		chunk_size = arr_count / 14;
	return (chunk_size);
}

static void	chunk_insert_b(t_total *stacks, int c_size, int *rr, long *offset)
{
	int	current_index;

	current_index = ((stacks)->stack_a)->index;
	if (current_index < c_size + *offset)
	{
		if (*rr == 1)
		{
			rotate_b(stacks);
			*rr = 0;
		}
		if (((stacks)->stack_a)->index <= (*offset))
			*rr = 1;
		push_b(stacks);
		(*offset)++;
	}
	else
	{
		if (*rr == 1)
		{
			repeated_rotate(stacks);
			*rr = 0;
		}
		else
			rotate_a(stacks);
	}
}

static void	chunk_insert_b_prep(t_total *stacks, int arr_count)
{
	long	chunk_size;
	int		rr_flag;
	long	offset;

	offset = 0;
	rr_flag = 0;
	chunk_size = set_chunk_size(arr_count);
	while (stack_size((&stacks->stack_a)))
		chunk_insert_b(stacks, chunk_size, &rr_flag, &offset);
}

static int	find_max_and_index(t_stack *stack, int *index)
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
	*index = max_index;
	return (max_pos);
}

void	medium_algorithm(t_total *stacks)
{
	int	target_position;
	int	target_index;
	int	arr_count;

	arr_count = stack_size(&stacks->stack_a);
	while (stack_size(&stacks->stack_b) < arr_count)
		chunk_insert_b_prep(stacks, arr_count);
	while (stack_size(&stacks->stack_a) < arr_count)
	{
		target_position = find_max_and_index((stacks)->stack_b, &target_index);
		btoamod(stacks, target_position, target_index);
	}
}
