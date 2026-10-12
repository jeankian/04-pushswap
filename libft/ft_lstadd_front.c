/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 18:07:42 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/09 18:58:49 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
	while (ptr != NULL)
	{
		printf("%s\n",(char *)ptr->content);
		ptr = ptr->next;
	}
}*/
