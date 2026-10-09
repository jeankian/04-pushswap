/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili@student.42kl.edu.my <xin-jili>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:38:45 by xin-jili@st       #+#    #+#             */
/*   Updated: 2026/10/09 19:55:15 by xin-jili@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
// create_index_stacks
// -build
// -sort array
// -match stack and array
// -indexing stack

t_stack	*build_stack(int *array)
{
	int		array_count;
	int		i;
	t_stack	*stack;
	t_stack	*new_element;

	array_count = sizeof(array)/sizeof(array[0]);
	i = 0;
	stack = NULL;
	while (i < array_count)
	{
		new_element = ft_stack_new(array[i]);
		if (!new_element)
		{
			ft_stack_clear(&stack, &free);
			return (NULL);
		}
		ft_stack_addback(&stack, &new_element);
		i++;
	}
	return (stack);
}