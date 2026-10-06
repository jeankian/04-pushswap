/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:03:52 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/03 17:43:20 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_correct(t_total *stacks)
{
	t_stack	*current;

	current = stacks->stack_a;
	if (stacks->stack_b != NULL)
		return (0);
	while (current != NULL && current->next != NULL)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
