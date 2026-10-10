/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:49:52 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:49:54 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compare the first num bytes of ptr1 and ptr2
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *) ptr1;
	p2 = (const unsigned char *) ptr2;
	while (num > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		num--;
		p1++;
		p2++;
	}
	return (0);
}
