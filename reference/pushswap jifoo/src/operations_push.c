/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 13:47:36 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/03 17:45:56 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a_actual(t_stack **top_of_a, t_stack **top_of_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	if (!top_of_b || !*top_of_b)
		return ;
	current_a = *top_of_a;
	current_b = *top_of_b;
	*top_of_b = current_b->next;
	current_b->next = current_a;
	*top_of_a = current_b;
}

static void	push_b_actual(t_stack **top_of_a, t_stack **top_of_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	if (!top_of_a || !*top_of_a)
		return ;
	current_a = *top_of_a;
	current_b = *top_of_b;
	*top_of_a = current_a->next;
	current_a->next = current_b;
	*top_of_b = current_a;
}

void	push_a(t_total *stacks)
{
	push_a_actual(&stacks->stack_a, &stacks->stack_b);
	stacks->moves.pa++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("pa\n");
}

void	push_b(t_total *stacks)
{
	push_b_actual(&stacks->stack_a, &stacks->stack_b);
	stacks->moves.pb++;
	stacks->moves.total++;
	if (BONUS == 0)
		ft_printf("pb\n");
}
