/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:31:46 by xin-jili          #+#    #+#             */
/*   Updated: 2026/10/18 14:21:41 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b)->next;
	ft_stack_addfront(stack_a, *stack_b);
	*stack_b = temp;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_a))
		return ;
	temp = (*stack_a)->next;
	ft_stack_addfront(stack_b, *stack_a);
	*stack_a = temp;
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
// 	pb(&stack_a, &stack_b);
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