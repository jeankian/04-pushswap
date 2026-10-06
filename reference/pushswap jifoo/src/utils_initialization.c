/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 00:00:00 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 17:26:15 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_moves(t_moves *moves)
{
	moves->sa = 0;
	moves->sb = 0;
	moves->ss = 0;
	moves->pa = 0;
	moves->pb = 0;
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
	moves->total = 0;
}

void	handle_args(int argc, char **argv, t_total *stacks)
{
	int	*arr;
	int	arr_count;

	if (argc == 2)
		arr = parse_one_arg(argv[1], &arr_count);
	else
		arr = parse_multi_args(argc, argv, &arr_count);
	if (check_duplicates(arr, arr_count) || arr_count == 0)
	{
		free(arr);
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	stacks->stack_a = build_stack(arr, arr_count);
	if (!stacks->stack_a)
	{
		free(arr);
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	stacks->stack_a = index_stack(stacks->stack_a, arr, arr_count);
	init_moves(&stacks->moves);
	free(arr);
}
