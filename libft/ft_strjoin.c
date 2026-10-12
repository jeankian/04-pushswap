/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:14:53 by xin-jili          #+#    #+#             */
/*   Updated: 2026/08/06 15:16:22 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	str_len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_len = s1_len + s2_len;
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_len)
		str[i++] = *s1++;
	while (i < str_len)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	// char const	*s1 = "hello ";
	//char const	*s2 = "world";
	char	*new_str = ft_strjoin(NULL, NULL);
	
	printf("%s\n", new_str);
	free(new_str);
}*/
