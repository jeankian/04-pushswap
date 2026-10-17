/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:06:59 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:06:59 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (*lst == NULL)
		*lst = new;
	else
	{
		i = *lst;
		while (i->next != NULL)
			i = i->next;
		i->next = new;
	}
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
	t_list	*new = ft_lstnew("trees");

	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;

	printf("before: \n");
	printf("address of first: %p | content: %s | next: %p\n", 
		first, (char *)first->content, first->next);
	printf("address of second: %p | content: %s | next: %p\n", 
		second, (char *)second->content, second->next);
	printf("address of third: %p | content: %s | next: %p\n", 
		third, (char *)third->content, third->next);
	printf("address of fourth: %p | content: %s | next: %p\n", 
		fourth, (char *)fourth->content, fourth->next);
	printf("address of new: %p | content: %s | next: %p\n", 
		new, (char *)new->content, new->next);

	ft_lstadd_back(&first, new);

	printf("after: \n");
	printf("address of first: %p | content: %s | next: %p\n", 
		first, (char *)first->content, first->next);
	printf("address of second: %p | content: %s | next: %p\n", 
		second, (char *)second->content, second->next);
	printf("address of third: %p | content: %s | next: %p\n", 
		third, (char *)third->content, third->next);
	printf("address of fourth: %p | content: %s | next: %p\n", 
		fourth, (char *)fourth->content, fourth->next);
	printf("address of new: %p | content: %s | next: %p\n", 
		new, (char *)new->content, new->next);

	free(first);
	free(second);
	free(third);
	free(fourth);
	free(new);

	return(0);
}
*/