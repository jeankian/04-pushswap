/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 14:20:55 by xin-jili          #+#    #+#             */
/*   Updated: 2026/10/21 13:16:43 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	last = ft_stack_last(*stack);
	ft_stack_addfront(stack, last);
	second_last = *stack;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
}
void	rra(t_data *data)
{
	reverse_rotate(&data->stack_a);
	data->operations.count_rra++;
	data->operations.count_total++;
	ft_putstr_fd("rra\n", 1);
}
void	rrb(t_data *data)
{
	reverse_rotate(&data->stack_b);
	data->operations.count_rrb++;
	data->operations.count_total++;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data *data)
{
	reverse_rotate(&data->stack_a);
	reverse_rotate(&data->stack_b);
	data->operations.count_rrr++;
	data->operations.count_total++;
	ft_putstr_fd("rrr\n", 1);
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
// 	rra(&data);
// 	rrb(&data);
// 	rrr(&data);
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