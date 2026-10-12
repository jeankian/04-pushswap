/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:07:53 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/11 15:02:02 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void	str_capital(void *content)
{
	char	*str;
	str = (char *)content;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	**lst;
	int		i;
	t_list	*ptr;
	t_list	*temp;

	if (argc == 1)
		return (1);
	lst = (t_list **)malloc(sizeof(t_list *));
	if (!lst)
		return (1);
	i = 1;
	*lst = ft_lstnew(ft_strdup(argv[i]));
	if (!lst)
		return (1);
	ptr = *lst;
	while (++i < argc)
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(argv[i])));
	ft_lstiter(ptr, &str_capital);
	while (ptr != NULL)
	{
		printf("%s\n", (char *)ptr->content);
		temp = ptr;
		ptr = ptr->next;
		ft_lstdelone(temp, &free);
	}
}*/