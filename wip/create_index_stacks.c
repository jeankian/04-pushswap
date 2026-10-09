/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili@student.42kl.edu.my <xin-jili>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:38:45 by xin-jili@st       #+#    #+#             */
/*   Updated: 2026/10/09 21:20:28 by xin-jili@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
// create_index_stacks
// -build
// -sort array
// -match stack and array
// -indexing stack

t_stack	*build_stack(int *array, int array_size)
{
	int		i;
	t_stack	*stack;
	t_stack	*new_element;

	i = 0;
	stack = NULL;
	while (i < array_size)
	{
		new_element = ft_stack_new(array[i]);
		if (!new_element)
		{
			ft_stack_clear(&stack);
			return (NULL);
		}
		ft_stack_addback(&stack, new_element);
		i++;
	}
	return (stack);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int array[] = {9, 3, 4, 1, 2};
// 	int array_size;
// 	int	i;
// 	t_stack	*stack;

// 	array_size = sizeof(array)/sizeof(array[0]);
// 	stack = build_stack(array, array_size);
// 	i = 0;
// 	while (i < array_size)
// 	{
// 		printf("%i", stack->content);
// 		stack = stack->next;
// 		i++;
// 	}
// }