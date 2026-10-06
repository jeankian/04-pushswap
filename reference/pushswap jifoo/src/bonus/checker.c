/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:22:15 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/03 17:39:22 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_stack	*next_node;
	t_stack	*current_node;

	current_node = stack;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}

static int	isvalid_operation(char *operation)
{
	const char	*valid_operations[] = {
		"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
	};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(operation, valid_operations[i],
				ft_strlen(valid_operations[i]) + 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	perform_operation(t_total *stacks, char *operation)
{
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		swap_a(stacks);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		swap_b(stacks);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		super_swap(stacks);
	else if (ft_strncmp(operation, "pa\n", 3) == 0)
		push_a(stacks);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		push_b(stacks);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		rotate_a(stacks);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rotate_b(stacks);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		repeated_rotate(stacks);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		reverse_rotate_a(stacks);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		reverse_rotate_b(stacks);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		repeated_reverse_rotate(stacks);
	free(operation);
}

static void	time4sort(t_total *stacks)
{
	char	*operation;

	while (1)
	{
		operation = get_next_line(0);
		if (!operation)
			break ;
		if (isvalid_operation(operation))
			perform_operation(stacks, operation);
		else
		{
			free(operation);
			free_stack(stacks->stack_a);
			free_stack(stacks->stack_b);
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_total	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	if (argc < 2)
		return (0);
	else
		handle_args(argc, argv, &stacks);
	time4sort(&stacks);
	if (is_it_correct(&stacks))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	return (0);
}
