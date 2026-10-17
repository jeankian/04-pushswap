/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:07:06 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:07:06 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
	t_list	*first = ft_lstnew("summer");
	t_list	*second= ft_lstnew("car");
	t_list	*new = ft_lstnew("my");

	printf("before: \n");
	printf("address of first: %p | content: %s | next: %p\n", 
		first, (char *)first->content, first->next);
	printf("address of second: %p | content: %s | next: %p\n", 
		second, (char *)second->content, second->next);
	printf("address of new: %p | content: %s | next: %p\n", 
		new, (char *)new->content, new->next);

	first->next = second;

	printf("after linking first & second: \n");
	printf("address of first: %p | content: %s | next: %p\n", 
		first, (char *)first->content, first->next);
	printf("address of second: %p | content: %s | next: %p\n", 
		second, (char *)second->content, second->next);
	printf("address of new: %p | content: %s | next: %p\n", 
		new, (char *)new->content, new->next);

	ft_lstadd_front(&first, new);	

	printf("after putting new in front: \n");
	printf("address of first: %p | content: %s | next: %p\n", 
		first, (char *)first->content, first->next);

	t_list	*new_second = first->next;
	t_list	*new_third = new_second->next;

	printf("address of second: %p | content: %s | next: %p\n", 
		new_second, (char *)new_second->content, new_second->next);
	printf("address of third: %p | content: %s | next: %p\n", 
		new_third, (char *)new_third->content, new_third->next);

	free(first);
	free(new_second);
	free(new_third);

	return(0);
}
*/