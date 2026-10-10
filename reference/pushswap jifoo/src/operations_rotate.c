/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:22:43 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/02 21:21:43 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a_actual(t_stack **top_of_a)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!top_of_a)
		return ;
	first_node = *top_of_a;
	last_node = ft_stklast(first_node);
	if (last_node == first_node)
		return ;
	last_node->next = first_node;
	*top_of_a = first_node->next;
	first_node->next = NULL;
	return ;
}

static void	rotate_b_actual(t_stack **top_of_b)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!top_of_b)
		return ;
	first_node = *top_of_b;
	last_node = ft_stklast(first_node);
	if (last_node == first_node)
		return ;
	last_node->next = first_node;
	*top_of_b = first_node->next;
	first_node->next = NULL;
	return ;
}

void	repeated_rotate(t_total *stacks)
{
	rotate_a_actual(&stacks->stack_a);
	rotate_b_actual(&stacks->stack_b);
	stacks->moves.rr++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("rr\n");
}

void	rotate_b(t_total *stacks)
{
	rotate_b_actual(&stacks->stack_b);
	stacks->moves.rb++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("rb\n");
}

void	rotate_a(t_total *stacks)
{
	rotate_a_actual(&stacks->stack_a);
	stacks->moves.ra++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("ra\n");
}
