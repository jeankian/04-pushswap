/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:50:10 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:50:11 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//fill specified memory with a constant byte value
void	*ft_memset(void *ptr, int x, size_t len)
{
	unsigned char	*dst;

	dst = ptr;
	while (len > 0)
	{
		*dst = (unsigned char) x;
		dst++;
		len--;
	}
	return (ptr);
}
