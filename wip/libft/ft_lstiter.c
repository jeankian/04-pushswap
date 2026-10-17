/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:07:37 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:07:37 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*i;

	if (lst == NULL)
		return ;
	i = lst;
	while (i != NULL)
	{
		f(i->content);
		i = i->next;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>

void	f(void *content)
{
	int i = 0;
	char *c;
	c = content;
	while(c[i])
	{
		c[i] = c[i] - 1;
		i++;
	}
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
	char	f1[] = "my";
	char	s1[] = "summer";
	char	t1[] = "car";
	t_list	*first = ft_lstnew(f1);	
	t_list	*second= ft_lstnew(s1);
	t_list	*third = ft_lstnew(t1);

	first->next = second;
	second->next = third;
	third->next = NULL;

	printf("before: \n");
	printf("first: %s\n", (char *)first->content);
	printf("second: %s\n", (char *)second->content);
	printf("third: %s\n", (char *)third->content);

	ft_lstiter(first, f);

	printf("after: \n");
	printf("first: %s\n", (char *)first->content);
	printf("second: %s\n", (char *)second->content);
	printf("third: %s\n", (char *)third->content);

	free(first);
	free(second);
	free(third);

	return(0);
}
*/