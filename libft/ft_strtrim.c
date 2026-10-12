/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:02:47 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/24 10:59:45 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

/*#include <stdio.h>
int	main(void)
{
	char const	*s1 = "   xxxtripouille   xxx";
	char const	*set = " x";
	char	*trimmed_str = ft_strtrim(s1, set);
	if (!trimmed_str)
		return (0);
	printf("%s\n", trimmed_str);
	free(trimmed_str);
}*/