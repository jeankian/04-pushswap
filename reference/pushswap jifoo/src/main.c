/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 13:15:55 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/07 14:24:26 by jia-liew         ###   ########.fr       */
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

static void	run_algorithm(t_total *stacks, t_algo algorithm)
{
	if (algorithm == ALGO_SIMPLE)
		simple_algorithm(stacks);
	else if (algorithm == ALGO_MEDIUM)
		medium_algorithm(stacks);
	else if (algorithm == ALGO_COMPLEX)
		complex_algorithm(stacks);
	else
		adaptive_algorithm(stacks);
}

static t_algo	get_algorithm(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (ALGO_SIMPLE);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (ALGO_MEDIUM);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (ALGO_COMPLEX);
	return (ALGO_ADAPTIVE);
}

static t_algo	select_algorithm(int *argc, char ***argv, t_total *stacks)
{
	if (ft_strncmp(&(*argv)[1][1], "-", 1) != 0)
		return (ALGO_ADAPTIVE);
	if (ft_strncmp((*argv)[1], "--bench", 8) == 0)
	{
		stacks->bench = true;
		(*argc)--;
		(*argv)++;
	}
	if (*argc < 2)
		return (ALGO_ADAPTIVE);
	if (ft_strncmp(&(*argv)[1][1], "-", 1) != 0)
		return (ALGO_ADAPTIVE);
	if (get_algorithm((*argv)[1]) == ALGO_ADAPTIVE
		&& ft_strncmp((*argv)[1], "--adaptive", 11) != 0)
		return (ALGO_ADAPTIVE);
	(*argc)--;
	(*argv)++;
	return (get_algorithm((*argv)[0]));
}

int	main(int argc, char **argv)
{
	t_total	stacks;
	t_algo	algorithm;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.bench = false;
	if (argc < 2)
		return (0);
	algorithm = select_algorithm(&argc, &argv, &stacks);
	if (argc < 2)
		return (0);
	handle_args(argc, argv, &stacks);
	stacks.disorder = compute_disorder(stacks.stack_a);
	run_algorithm(&stacks, algorithm);
	if (stacks.bench)
		benchmark_mode(&stacks, algorithm);
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	return (0);
}
