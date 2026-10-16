/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili@student.42kl.edu.my <xin-jili>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:37:31 by xin-jili          #+#    #+#             */
/*   Updated: 2026/10/16 22:35:23 by xin-jili@st      ###   ########.fr       */
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