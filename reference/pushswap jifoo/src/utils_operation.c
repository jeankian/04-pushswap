/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:22:37 by jia-liew          #+#    #+#             */
/*   Updated: 2026/10/03 13:19:48 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stklast(t_stack *stk)
{
	t_stack	*current;

	if (!stk)
		return (NULL);
	current = stk;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_stack	*ft_stknew(void *content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		last = ft_stklast(*lst);
		last->next = new;
	}
}
