/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:17:19 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/12 09:09:03 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*return_mem;
	char	*p_return;
	size_t	i;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	return_mem = (void *)malloc(nmemb * size);
	if (!return_mem)
		return (NULL);
	p_return = (char *)return_mem;
	i = 0;
	while (i < nmemb * size)
	{
		p_return[i] = 0;
		i++;
	}
	return (return_mem);
}

/*#include <stdio.h>
int	main(void)
{
	char	*calloc_test;
	// size_t	i;
	
	calloc_test = ft_calloc(2147483647, 2147483647);
	if (!calloc_test)
	{
		printf("error");
		return (1);
	}
	// i = 0;
	// while (i < 4)
	// {
	// 	printf("%c\n", calloc_test[i]);
	// 	i++;
	// }
	free(calloc_test);
}*/