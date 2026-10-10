/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:24:51 by jia-liew          #+#    #+#             */
/*   Updated: 2026/08/13 16:10:08 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*strdup_mod(char *s);
static int	reached(const char *s);
static char	*refreshbuffer(char *old_buffer, int size_to_remove);
static char	*readandadd(const int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*output_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = readandadd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (buffer[fd][0] == '\0')
	{
		buffer[fd] = NULL;
		return (NULL);
	}
	output_string = strdup_mod((char *)buffer[fd]);
	buffer[fd] = refreshbuffer((char *)buffer[fd], (ft_strlen(output_string)));
	return (output_string);
}

static char	*strdup_mod(char *s)
{
	unsigned long		i;
	char				*output_string;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	output_string = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		output_string[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		output_string[i] = '\n';
		i++;
	}
	output_string[i] = '\0';
	return (output_string);
}

static int	reached(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

static char	*refreshbuffer(char *old_buffer, int size_to_remove)
{
	int		i;
	char	*new_buffer;

	i = 0;
	new_buffer = (char *)malloc((ft_strlen(old_buffer) - size_to_remove + 1));
	if (!new_buffer)
	{
		free(old_buffer);
		return (NULL);
	}
	if (old_buffer[size_to_remove + i] == '\0')
	{
		free (old_buffer);
		return (free(new_buffer), NULL);
	}
	while (old_buffer[size_to_remove + i])
	{
		new_buffer[i] = old_buffer[size_to_remove + i];
		i++;
	}
	new_buffer[i] = '\0';
	free(old_buffer);
	return (new_buffer);
}

static char	*readandadd(const int fd, char *buffer)
{
	char	*temp_buffer;
	int		read_status;

	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	read_status = 1;
	while (!reached(buffer) && read_status != 0)
	{
		read_status = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_status == -1)
		{
			free(temp_buffer);
			return (free(buffer), NULL);
		}
		temp_buffer[read_status] = '\0';
		if (read_status != 0)
			buffer = ft_strjoin(buffer, temp_buffer);
	}
	return (free(temp_buffer), buffer);
}
