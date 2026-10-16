/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili@student.42kl.edu.my <xin-jili>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:45:12 by xin-jili@st       #+#    #+#             */
/*   Updated: 2026/10/16 22:13:16 by xin-jili@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	reverse_rotate_a(t_stack **stack_a)
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
void	reverse_rotate_b(t_stack **stack_b)
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

void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
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
// 	reverse_rotate_a(&stack_a);
// 	reverse_rotate_b(&stack_b);
// 	reverse_rotate_r(&stack_a, &stack_b);
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