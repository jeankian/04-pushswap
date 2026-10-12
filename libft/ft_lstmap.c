/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:28:40 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/21 15:51:29 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

/*#include <stdio.h>
void	*str_capital(void *content)
{
	char	*str;
	str = (char *)content;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (content);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*new_lst;
	int	i;

	if (argc == 1)
		return (1);
	i = 1;
	lst = ft_lstnew(ft_strdup(argv[i]));
	if (!lst)
		return (1);
	while (++i < argc)
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(argv[i])));
	new_lst = ft_lstmap(lst, &str_capital, &free);
	printf("Original list: \n");
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	printf("New list: \n");
	while (new_lst)
	{
		printf("%s\n", (char *)new_lst->content);
		new_lst = new_lst->next;
	}
}*/