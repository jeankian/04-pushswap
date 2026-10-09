/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index_stacks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili@student.42kl.edu.my <xin-jili>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 19:38:45 by xin-jili@st       #+#    #+#             */
/*   Updated: 2026/10/10 00:29:48 by xin-jili@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_array(int *array, int array_size)
{
	quicksort_array(array, 0, array_size - 1);
}

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

int	find_index(int content, int *array, int array_size)
{
	int	index;

	index = 0;
	while (index < array_size)
	{
		if (content == array[index])
			break;
		index++;
	}
	return (index);
}

void	index_stack(t_stack *stack, int *array, int array_size)
{
	int	index;

	sort_array(array, array_size);
	while (stack != NULL)
	{
		index = find_index(stack->content, array, array_size);
		stack->index = index;
		stack = stack->next;
	}
}
// print out sorted array
// #include <stdio.h>
// int	main(void)
// {
// 	int array[] = {929839, 3, -4, 10, 2, 526, 7, -12};
// 	int array_size;
// 	int	i;

// 	array_size = sizeof(array)/sizeof(array[0]);
// 	i = 0;
// 	sort_array(array, array_size);
// 	while (i < array_size)
// 	{
// 		printf("%i, ", array[i]);
// 		i++;
// 	}
// }


// print out stack
// #include <stdio.h>
// int	main(void)
// {
// 	int array[] = {929839, 3, -4, 10, 2, 526, 7, -12};
// 	int array_size;
// 	int	i;
// 	t_stack	*stack;
// 	t_stack	*ptr;

// 	array_size = sizeof(array)/sizeof(array[0]);
// 	stack = build_stack(array, array_size);
// 	i = 0;
// 	printf("stack original content:\n");
// 	ptr = stack;
// 	while (i < array_size)
// 	{
// 		printf("%i, ", ptr->content);
// 		ptr = ptr->next;
// 		i++;
// 	}

// 	printf("\n");
// 	index_stack(stack, array, array_size);
// 	ptr = stack;
// 	printf("\nstack index value:\n");
// 	while (ptr != NULL)
// 	{
// 		printf("%i, ", ptr->index);
// 		ptr = ptr->next;
// 	}
// }
