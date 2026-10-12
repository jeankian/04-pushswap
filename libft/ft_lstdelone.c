/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 12:11:43 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/10 14:52:00 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

/*#include <stdio.h>
int	main(void)
{
	char	*content;
	t_list	*lst;

	content = ft_strdup("hello");
	if (!content)
		return (1);
	lst = ft_lstnew(content);
	if (!lst)
		return (1);
	printf("%s\n", (char *)lst->content);
	ft_lstdelone(lst, &free);
}*/