/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:47:06 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:47:09 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//allocate memory for an array of nmemb elements of size bytes
//each and initialize all bytes to zero
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max_size;

	max_size = (size_t)-1;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > max_size / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
