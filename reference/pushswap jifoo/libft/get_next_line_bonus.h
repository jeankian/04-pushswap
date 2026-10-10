/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 18:01:22 by jia-liew          #+#    #+#             */
/*   Updated: 2026/08/13 16:08:07 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);
#endif
