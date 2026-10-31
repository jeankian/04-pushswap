/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:37:31 by xin-jili          #+#    #+#             */
/*   Updated: 2026/10/21 13:16:36 by xin-jili         ###   ########.fr       */
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

typedef struct s_ops
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
	int			count_total;
}	t_ops;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_ops	operations;
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

//operations
void	pa(t_data *data);
void	pb(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

#endif