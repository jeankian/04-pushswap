/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xin-jili <xin-jili@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:47:21 by xin-jili          #+#    #+#             */
/*   Updated: 2026/09/29 14:28:53 by xin-jili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_line(char *stash, int fd)
{
	char	*appended_stash;
	char	*line_read;
	int		bytes_read;

	line_read = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line_read)
		return (NULL);
	bytes_read = read(fd, line_read, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(line_read), free(stash), NULL);
	while (bytes_read > 0)
	{
		line_read[bytes_read] = '\0';
		appended_stash = ft_strjoin_gnl(stash, line_read);
		free(stash);
		stash = appended_stash;
		if (ft_strchr_gnl(stash, '\n'))
			break ;
		bytes_read = read(fd, line_read, BUFFER_SIZE);
	}
	return (free(line_read), stash);
}

char	*extract_line(char *stash)
{
	size_t	i;
	char	*next_line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	i++;
	next_line = ft_substr_gnl(stash, 0, i);
	return (next_line);
}

void	clean_up_stash(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i])
		i++;
	ft_strcpy_gnl(stash, &stash[i]);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = get_line(stash, fd);
	if (!stash)
		return (NULL);
	next_line = extract_line(stash);
	clean_up_stash(stash);
	return (next_line);
}
