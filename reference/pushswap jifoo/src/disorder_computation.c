/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_computation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 16:01:41 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/07 14:27:30 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack_a)
{
	long	mistakes;
	long	total_pairs;
	t_stack	*i;
	t_stack	*j;

	if (stack_a == NULL || stack_a->next == NULL)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = stack_a;
	while (i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs += 1;
			if (i->index > j->index)
				mistakes += 1;
			j = j->next;
		}
		i = i->next;
	}
	return ((float)mistakes / (float)total_pairs);
}
