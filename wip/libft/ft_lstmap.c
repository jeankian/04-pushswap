/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:07:54 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:07:54 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
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

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

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

void	*f(void *content)
{
	int i = 0;
	char *c;
	c = content;
	while(c[i])
	{
		c[i] = c[i] - 1;
		i++;
	}
	return (c);
}

void	del(void *content)
{
	(void)content;
	return ;
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*newnode;
	void	*newcontent;

	n = NULL;
	while (lst != NULL)
	{
		newcontent = f(lst->content);
		if (newcontent == NULL)
		{
			ft_lstclear(&n, del);
			return (NULL);
		}
		newnode = ft_lstnew(newcontent);
		if (newnode == NULL)
		{
			del(newcontent);
			ft_lstclear(&n, del);
			return (NULL);
		}
		ft_lstadd_back(&n, newnode);
		lst = lst->next;
	}
	return (n);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*newlist;

	char	f1[] = "my";
	char	s1[] = "summer";
	char	t1[] = "car";
	t_list	*first = ft_lstnew(f1);	
	t_list	*second= ft_lstnew(s1);
	t_list	*third = ft_lstnew(t1);

	first->next = second;
	second->next = third;
	third->next = NULL;

	printf("ori list: \n");
	printf("first: %s\n", (char *)first->content);
	printf("second: %s\n", (char *)second->content);
	printf("third: %s\n", (char *)third->content);
	printf("\n");
	newlist = ft_lstmap(first, f, del);

	t_list	*n_first;
	t_list	*n_second;
	t_list	*n_third;

	n_first = newlist;	
	n_second = n_first->next;
	n_third = n_second->next;

	printf("copied list: \n");
	printf("first: %s\n", (char *)n_first->content);
	printf("second: %s\n", (char *)n_second->content);
	printf("third: %s\n", (char *)n_third->content);

	free(first);
	free(second);
	free(third);

	free(n_first);
	free(n_second);
	free(n_third);

	return(0);
}
*/