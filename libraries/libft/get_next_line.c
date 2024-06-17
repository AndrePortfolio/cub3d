/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:39:48 by btoksoez          #+#    #+#             */
/*   Updated: 2024/06/12 12:34:54 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_stringlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_stringjoin(char *line, char *buffer)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(ft_stringlen(line) + ft_stringlen(buffer) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (line && line[i])
	{
		res[i] = ((char *)line)[i];
		i++;
	}
	if (line)
		free(line);
	j = 0;
	while (buffer[j])
	{
		res[i++] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	res[i] = '\0';
	return (res);
}

void	clean_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i++] = 0;
	}
}

int	shift_buffer(char *buffer)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (buffer[i])
	{
		if (found == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			found = 1;
		buffer[i++] = '\0';
	}
	return (found);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		clean_buffer(buffer);
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_stringjoin(line, buffer);
		if (shift_buffer(buffer))
			break ;
	}
	return (line);
}
