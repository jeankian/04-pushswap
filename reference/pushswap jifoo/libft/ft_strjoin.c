/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:51:06 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/04 14:51:06 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Allocates memory and returns a new concatenated string
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s_len;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	s_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_s = malloc(s_len);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, s_len);
	ft_strlcat(new_s, s2, s_len);
	return (new_s);
}
