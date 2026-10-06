/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 16:29:28 by jia-liew          #+#    #+#             */
/*   Updated: 2026/09/03 17:39:07 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
You put in: An array of numbers (*array_of_numbers)
You get back: A pointer to head node of linked list 
containing all numbers (*new_lst)
*/

static void	lst_delone_pushswap(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

static void	lst_clear_pushswap(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		lst_delone_pushswap(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

t_stack	*build_stack(int array_of_numbers[], int size)
{
	int		i;
	t_stack	*new_lst;
	t_stack	*new_node;

	new_lst = NULL;
	i = 0;
	while (i < size)
	{
		new_node = ft_stknew(&array_of_numbers[i]);
		if (!new_node)
		{
			lst_clear_pushswap(&new_lst);
			return (NULL);
		}
		ft_stkadd_back(&new_lst, new_node);
		i++;
	}
	return (new_lst);
}
