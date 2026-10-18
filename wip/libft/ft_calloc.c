/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkian <jkian@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:05:46 by jkian             #+#    #+#             */
/*   Updated: 2026/08/17 17:05:46 by jkian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include <stdint.h>
/*
#include <stddef.h>

#include <stdio.h>
*/

void	*ft_calloc(size_t elnum, size_t elsize)
{
	unsigned char	*ptr;
	size_t			total;
	size_t			i;

	if (elnum != 0 && elsize > (SIZE_MAX / elnum))
		return (NULL);
	if (elnum == 0 || elsize == 0)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	total = elnum * elsize;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int	main(void)
{
	unsigned char	*calloc_a1;
	unsigned char	*calloc_a2;
	size_t	elnum = 3;
	size_t	elsize = 1;
	size_t	calloc_p = elnum * elsize;
	calloc_a1 = ft_calloc(elnum, elsize);
	calloc_a2 = calloc(elnum, elsize);
	
	if (calloc_a1 == NULL)
		printf("ft_calloc is NULL\n");
	if (calloc_a2 == NULL)
		printf("calloc is NULL\n");

	size_t	calloc_i = 0;
	while (calloc_i < calloc_p)
	{
		printf("ft_calloc: %d ", calloc_a1[calloc_i]);
		printf("calloc: %d\n ", calloc_a2[calloc_i]);
		calloc_i++;
	}	
	free(calloc_a1);
	free(calloc_a2);

	return (0);
}
*/
