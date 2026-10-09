/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili@student.42kl.edu.my <xin-jili>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 21:40:08 by xin-jili@st       #+#    #+#             */
/*   Updated: 2026/10/09 21:20:10 by xin-jili@st      ###   ########.fr       */
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

//create stacks utils
t_stack	*ft_stack_new(int content);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_addback(t_stack **stack, t_stack *new_element);
void	ft_stack_delone(t_stack *element);
void	ft_stack_clear(t_stack **stack);

#endif