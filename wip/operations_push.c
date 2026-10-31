/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 13:31:46 by xin-jili          #+#    #+#             */
/*   Updated: 2026/10/21 13:22:03 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*temp;

	if (!(*stack_1))
		return ;
	temp = (*stack_1)->next;
	ft_stack_addfront(stack_2, *stack_1);
	*stack_1 = temp;
}

void	pa(t_data *data)
{
	push(&data->stack_b, &data->stack_a);
	data->operations.count_pa++;
	data->operations.count_total++;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data)
{
	push(&data->stack_a, &data->stack_b);
	data->operations.count_pb++;
	data->operations.count_total++;
	ft_putstr_fd("pb\n", 1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_data	data;

// 	ft_bzero(&data, sizeof(data));
// 	int	array_a[] = {4, 9, 7};
// 	int	array_b[] = {1, 2, 3};

// 	data.stack_a = build_stack(array_a, 3);
// 	data.stack_b = build_stack(array_b, 3);
// 	pb(&data);
// 	t_stack	*ptr_a = data.stack_a;
// 	printf("stack_a\n");
// 	while (ptr_a)
// 	{
// 		printf("%d, ", ptr_a->content);
// 		ptr_a = ptr_a->next;
// 	}
// 	t_stack	*ptr_b = data.stack_b;
// 	printf("\nstack_b\n");
// 	while (ptr_b)
// 	{
// 		printf("%d, ", ptr_b->content);
// 		ptr_b = ptr_b->next;
// 	}
// 	ft_stack_clear(&data.stack_a);
// 	ft_stack_clear(&data.stack_b);
// }