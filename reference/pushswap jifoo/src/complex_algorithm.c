/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 14:30:13 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/02 14:41:02 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_plan	evaluate_cost(int index, int a_pos, int size_a,
		t_stack *stack_b)
{
	t_plan	current_plan;
	int		b_pos;

	b_pos = find_target_pos(stack_b, index);
	current_plan.a_cost = rotation_cost(a_pos, size_a);
	current_plan.b_cost = rotation_cost(b_pos, stack_size(&stack_b));
	current_plan.total_cost = combined_rotation_cost(current_plan.a_cost,
			current_plan.b_cost);
	current_plan.candidate_index = index;
	return (current_plan);
}

static t_plan	cheapest_plan_selector(t_total *stacks)
{
	int		a_pos;
	int		size_a;
	t_plan	current_plan;
	t_plan	cheapest_plan;
	t_stack	*current;

	a_pos = 0;
	size_a = stack_size(&stacks->stack_a);
	cheapest_plan.total_cost = INT_MAX;
	current = stacks->stack_a;
	while (current != NULL)
	{
		current_plan = evaluate_cost(current -> index, a_pos, size_a,
				stacks->stack_b);
		if (current_plan.total_cost < cheapest_plan.total_cost)
			cheapest_plan = current_plan;
		current = current -> next;
		a_pos++;
	}
	return (cheapest_plan);
}

static void	execute_plan(t_total *stacks, t_plan plan)
{
	while (plan.a_cost > 0 && plan.b_cost > 0)
	{
		repeated_rotate(stacks);
		plan.a_cost--;
		plan.b_cost--;
	}
	while (plan.a_cost < 0 && plan.b_cost < 0)
	{
		repeated_reverse_rotate(stacks);
		plan.a_cost++;
		plan.b_cost++;
	}
	rotate_stack_a(stacks, plan.a_cost);
	rotate_stack_b(stacks, plan.b_cost);
	push_b(stacks);
}

//turk sort
void	complex_algorithm(t_total *stacks)
{
	t_plan	cheapest_plan;
	int		target_pos;

	if (sort_checker(stacks))
		return ;
	if ((stacks->stack_b) == NULL)
	{
		push_b(stacks);
		push_b(stacks);
	}
	while (stack_size(&stacks->stack_a) > 3)
	{
		cheapest_plan = cheapest_plan_selector(stacks);
		execute_plan(stacks, cheapest_plan);
	}
	sort_three(stacks);
	while ((stacks->stack_b) != NULL)
	{
		target_pos = find_target_pos_2(stacks->stack_a,
				(stacks->stack_b)->index);
		move_a_pos_to_top(stacks, target_pos);
		push_a(stacks);
	}
	move_a_min_to_top(stacks);
}
