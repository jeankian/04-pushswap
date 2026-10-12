/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:38:12 by xin-jili          #+#    #+#             */
/*   Updated: 2026/09/10 16:53:11 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	if (!str)
		return (print_str("(null)"));
	count = 0;
	while (str[count])
	{
		print_char(str[count]);
		count++;
	}
	return (count);
}
