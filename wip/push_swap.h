/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:37:31 by xin-jili          #+#    #+#             */
/*   Updated: 2026/10/18 13:06:37 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int			count_sa;
	int			count_sb;
	int			count_ss;
	int			count_pa;
	int			count_pb;
	int			count_ra;
	int			count_rb;
	int			count_rr;
	int			count_rra;
	int			count_rrb;
	int			count_rrr;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_data;

//parsing utils
int		is_flag(char *argv);
void	*cleanup_tree(char **tree);
int		is_int(char *argv);
int		*str_to_int_array(char **numstr, int array_size);
int		is_not_dup(int *array, int array_size);

//create stacks utils
t_stack	*ft_stack_new(int content);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_addback(t_stack **stack, t_stack *new_element);
void	ft_stack_addfront(t_stack **stack, t_stack *new_element);
void	ft_stack_clear(t_stack **stack);

//create index stacks
t_stack	*build_stack(int *array, int array_size);
void	index_stack(t_stack *stack, int *array, int array_size);

//sort array utils
void	quicksort_array(int *array, int low, int high);

#endif