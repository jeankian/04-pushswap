/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:46:53 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/10 12:01:34 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*#include <stdio.h>
int	main(void)
{
	t_list	**list;
	t_list	*new;
	t_list	*ptr;

	list = (t_list **)malloc(sizeof(t_list *));
	if (!list)
		return (1);
	list[0] = ft_lstnew("first");
	if (!list[0])
		return (1);
	new = ft_lstnew("new first");
	if (!new)
		return (1);

	ft_lstadd_front(list, new);
	ptr = *list;
	printf("og list content: \n");
	while (ptr != NULL)
	{
		printf("%s\n",(char *)ptr->content);
		ptr = ptr->next;
	}
	ptr = ft_lstlast(*list);
	while (ptr != NULL)
	{
		printf("last content: %s\n",(char *)ptr->content);
		ptr = ptr->next;
	}
}*/