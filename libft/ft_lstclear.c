/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:44:48 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/11 15:09:54 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp, del);
	}
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	t_list **lst;
	int	i;
	//t_list	*ptr;

	if (argc == 1)
		return (1);
	i = 1;
	lst = (t_list **)malloc(sizeof(t_list *));
	if (!lst)
		return (1);
	*lst = ft_lstnew(ft_strdup(argv[i]));
	if (!lst)
		return (1);
	//ptr = *lst;
	while (++i < argc)
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(argv[i])));
	// while (ptr != NULL)
	// {
	// 	printf("%s\n", (char *)ptr->content);
	// 	ptr = ptr->next;
	// }
	ft_lstclear(lst, &free);
	printf("%p\n", *lst);
	free(lst);
}*/