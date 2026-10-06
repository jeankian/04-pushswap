/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 21:01:23 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/02 21:21:43 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_a_actual(t_stack **stack_a)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	if (!stack_a || !*stack_a)
		return ;
	first_node = *stack_a;
	second_node = first_node->next;
	if (!second_node)
		return ;
	third_node = second_node->next;
	first_node->next = third_node;
	second_node->next = first_node;
	*stack_a = second_node;
}

static void	swap_b_actual(t_stack **stack_b)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*third_node;

	if (!stack_b || !*stack_b)
		return ;
	first_node = *stack_b;
	second_node = first_node->next;
	if (!second_node)
		return ;
	third_node = second_node->next;
	first_node->next = third_node;
	second_node->next = first_node;
	*stack_b = second_node;
}

void	super_swap(t_total *stacks)
{
	swap_a_actual(&stacks->stack_a);
	swap_b_actual(&stacks->stack_b);
	stacks->moves.ss++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("ss\n");
}

void	swap_b(t_total *stacks)
{
	swap_b_actual(&stacks->stack_b);
	stacks->moves.sb++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("sb\n");
}

void	swap_a(t_total *stacks)
{
	swap_a_actual(&stacks->stack_a);
	stacks->moves.sa++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("sa\n");
}
