/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 16:04:43 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/07 14:29:50 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_algorithm(t_total *stacks)
{
	int	size;

	size = stack_size(&stacks->stack_a);
	if (stacks->disorder >= 0.5 || size <= 50)
		complex_algorithm(stacks);
	else if (stacks->disorder < 0.2 || size <= 100)
		medium_algorithm(stacks);
	else
		complex_algorithm(stacks);
}
