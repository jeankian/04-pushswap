/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 19:05:01 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/09 19:14:45 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;
	t_list			*ptr;

	if (!lst)
		return (0);
	count = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

/*#include <stdio.h>
int	main(void)
{
	t_list	*list;
	t_list	*new;
	unsigned int	count;

	list = ft_lstnew("first");
	if (!list)
		return (1);
	new = ft_lstnew("new first");
	if (!new)
		return (1);
	list->next = new;
	count = ft_lstsize(list);
	printf("%i", count);
}*/