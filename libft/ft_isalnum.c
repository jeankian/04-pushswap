/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:29:01 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/11 15:02:02 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

//extended solution
/*int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
*/

/*#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_isalnum('a'));
	printf("%i\n", ft_isalnum('Z'));
	printf("%i\n", ft_isalnum('0'));
	printf("%i\n", ft_isalnum('9'));
	printf("%i", ft_isalnum('@'));
}*/
