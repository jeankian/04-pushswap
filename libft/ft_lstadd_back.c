/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 12:04:05 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/11 15:06:56 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	t_list	*lst;
	int	i;
	t_list	*ptr;

	if (argc == 1)
		return (1);
	i = 1;
	lst = ft_lstnew(ft_strdup(argv[i]));
	while (++i < argc)
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(argv[i])));
	ptr = lst;
	while (ptr)
	{
		printf("%s\n", (char *)ptr->content);
		ptr = ptr->next;
	}
	return (0);
}*/
