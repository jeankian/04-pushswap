/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 13:47:36 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 17:42:48 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_a_actual(t_stack **stack_a)
{
	t_stack	*first_node;
	t_stack	*prev_node;
	t_stack	*current_node;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first_node = *stack_a;
	prev_node = NULL;
	current_node = first_node;
	while (current_node -> next != NULL)
	{
		prev_node = current_node;
		current_node = current_node -> next;
	}
	prev_node -> next = NULL;
	current_node -> next = first_node;
	*stack_a = current_node;
	return ;
}

static void	reverse_rotate_b_actual(t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*prev_node;
	t_stack	*current_node;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first_node = *stack_b;
	prev_node = NULL;
	current_node = first_node;
	while (current_node -> next != NULL)
	{
		prev_node = current_node;
		current_node = current_node -> next;
	}
	prev_node -> next = NULL;
	current_node -> next = first_node;
	*stack_b = current_node;
	return ;
}

void	repeated_reverse_rotate(t_total *stacks)
{
	reverse_rotate_a_actual(&stacks->stack_a);
	reverse_rotate_b_actual(&stacks->stack_b);
	stacks->moves.rrr++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("rrr\n");
}

void	reverse_rotate_b(t_total *stacks)
{
	reverse_rotate_b_actual(&stacks->stack_b);
	stacks->moves.rrb++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("rrb\n");
}

void	reverse_rotate_a(t_total *stacks)
{
	reverse_rotate_a_actual(&stacks->stack_a);
	stacks->moves.rra++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("rra\n");
}
