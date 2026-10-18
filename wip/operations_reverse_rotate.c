/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:20:55 by xin-jili          #+#    #+#             */
/*   Updated: 2026/10/18 14:20:57 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second_last;

	last = ft_stack_last(*stack_a);
	ft_stack_addfront(stack_a, last);
	second_last = *stack_a;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
}
void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*second_last;

	last = ft_stack_last(*stack_b);
	ft_stack_addfront(stack_b, last);
	second_last = *stack_b;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	int	array_a[] = {4, 9, 7};
// 	int	array_b[] = {1, 2, 3};

// 	stack_a = build_stack(array_a, 3);
// 	stack_b = build_stack(array_b, 3);
// 	rra(&stack_a);
// 	rrb(&stack_b);
// 	rrr(&stack_a, &stack_b);
// 	t_stack	*ptr_a = stack_a;
// 	printf("stack_a\n");
// 	while (ptr_a)
// 	{
// 		printf("%d, ", ptr_a->content);
// 		ptr_a = ptr_a->next;
// 	}
// 	t_stack	*ptr_b = stack_b;
// 	printf("\nstack_b\n");
// 	while (ptr_b)
// 	{
// 		printf("%d, ", ptr_b->content);
// 		ptr_b = ptr_b->next;
// 	}
// 	ft_stack_clear(&stack_a);
// 	ft_stack_clear(&stack_b);
// }