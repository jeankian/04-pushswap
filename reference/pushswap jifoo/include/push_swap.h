/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:27:53 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/03 17:41:32 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_stack
{
	void			*content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_moves
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_moves;

typedef struct s_total
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_moves	moves;
	float	disorder;
	bool	bench;
}	t_total;

typedef struct s_plan
{
	int	a_cost;
	int	b_cost;
	int	total_cost;
	int	candidate_index;
}	t_plan;

typedef enum e_algo
{
	ALGO_SIMPLE,
	ALGO_MEDIUM,
	ALGO_COMPLEX,
	ALGO_ADAPTIVE
}	t_algo;

# ifndef BONUS
#  define BONUS 0
# endif

/* Argument parsing and initialization */
int		*parse_one_arg(char *str, int *arr_count);
int		*parse_multi_args(int argc, char **argv, int *arr_count);
int		check_duplicates(int *arr, int count);
void	handle_args(int argc, char **argv, t_total *stacks);
void	init_moves(t_moves *moves);

/* Stack creation and indexing */
t_stack	*ft_stknew(void *content);
t_stack	*ft_stklast(t_stack *stk);
void	ft_stkadd_back(t_stack **lst, t_stack *new);
t_stack	*build_stack(int array_of_numbers[], int size);
t_stack	*index_stack(t_stack *stack, int *arr, int arr_count);
int		stack_size(t_stack **stack);

/* Swap operations */
void	swap_a(t_total *stacks);
void	swap_b(t_total *stacks);
void	super_swap(t_total *stacks);

/* Push operations */
void	push_a(t_total *stacks);
void	push_b(t_total *stacks);

/* Rotate operations */
void	rotate_a(t_total *stacks);
void	rotate_b(t_total *stacks);
void	repeated_rotate(t_total *stacks);

/* Reverse rotate operations */
void	reverse_rotate_a(t_total *stacks);
void	reverse_rotate_b(t_total *stacks);
void	repeated_reverse_rotate(t_total *stacks);

/* Stack position and target lookup */
int		find_max_pos(t_stack *stack);
int		find_min_pos(t_stack *stack);
int		find_target_pos(t_stack *stack_b, int x);
int		find_target_pos_2(t_stack *stack_a, int x);

/* Stack movement helpers */
void	move_b_pos_to_top(t_total *stacks, int pos);
void	move_a_pos_to_top(t_total *stacks, int pos);
void	move_a_min_to_top(t_total *stacks);
void	btoamod(t_total *stacks, int pos, int i);
void	rotate_stack_a(t_total *stacks, int cost);
void	rotate_stack_b(t_total *stacks, int cost);

/* Sorting state and cost calculations */
bool	sort_checker(t_total *stacks);
bool	is_circularly_sorted(t_stack *stack);
float	compute_disorder(t_stack *stack_a);
int		rotation_cost(int pos, int size);
int		combined_rotation_cost(int cost_a, int cost_b);

/* Sorting algorithms */
void	sort_three(t_total *stacks);
void	simple_algorithm(t_total *stacks);
void	medium_algorithm(t_total *stacks);
void	complex_algorithm(t_total *stacks);
void	adaptive_algorithm(t_total *stacks);

/* Benchmark output */
void	benchmark_mode(t_total *stacks, t_algo algorithm);
void	print_metric_inline(char *name, int value);
void	print_operations(t_moves *moves);
void	print_strategy(float disorder, t_algo algorithm);
void	print_disorder(float disorder);

/* Checker validation */
int		is_it_correct(t_total *stacks);

#endif
