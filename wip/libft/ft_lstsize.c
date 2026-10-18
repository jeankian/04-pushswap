/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:08:08 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:08:08 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	t_list			*t;
	unsigned int	i;

	t = lst;
	if (t == NULL)
		return (0);
	i = 0;
	while (t != NULL)
	{
		t = t->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node_a;

	node_a = malloc(sizeof(t_list));
	if (node_a == NULL)
		return (NULL);
	node_a->content = content;
	node_a->next = NULL;
	return (node_a);
}

int	main(void)
{
	t_list	*first = ft_lstnew("the");		
	t_list	*second= ft_lstnew("hidden");
	t_list	*third = ft_lstnew("life");
	t_list	*fourth = ft_lstnew("of");

	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;

	printf("%d\n", ft_lstsize(first));

	free(first);
	free(second);
	free(third);
	free(fourth);

	return(0);
}
*/