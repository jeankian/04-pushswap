/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:07:16 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:07:16 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return;
	del(lst->content);
	free(lst);
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*i;
	t_list	*j;

	if (*lst == NULL)
		return ;
	i = *lst;
	while (i != NULL)
	{
		j = i->next;
		ft_lstdelone(i, del);
		i = j;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

void	del(void *content)
{
	(void)content;
	return ;
}

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
	t_list	*first = ft_lstnew("my");		
	t_list	*second= ft_lstnew("summer");
	t_list	*third = ft_lstnew("car");

	first->next = second;
	second->next = third;
	third->next = NULL;

	printf("before: \n");
	printf("first: %s\n", (char *)first->content);
	printf("second: %s\n", (char *)second->content);
	printf("third: %s\n", (char *)third->content);

	ft_lstclear(&first, del);

	printf("first is NULL?: %d\n", first == NULL);

	return(0);
}
*/