/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:45:30 by egerin            #+#    #+#             */
/*   Updated: 2024/12/04 13:10:45 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ssize_t read (int fd, void *buf, size_t count);

#include "get_next_line.h"

char	*ft_joinfree(char *str, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(str, buffer);
	free(str);
	return (tmp);
}

char	*ft_next_line(char *buffer)
{
	int	i;
	int	j;
	char	*next_line;

	/* if (!buffer)
		return (free(buffer), NULL); */
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	next_line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
	{
		next_line[j++] = buffer[i++];
	}
	free (buffer);
	return (next_line);
}

char	*ft_first_line(char *buffer)
{
	int	i;
	char	*first_line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	first_line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		first_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		first_line[i++] = '\n';
	return (first_line);
}

char	*ft_read(int fd, char *str)
{
	int		bytes;
	char	*buffer;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes] = 0;
		str = ft_joinfree(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char *first_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	first_line = ft_first_line(buffer);
	buffer = ft_next_line(buffer);
	return (first_line);
}

/* #include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("Lecture du fichier =\n[%s]\n", get_next_line(fd));
	close(fd);
	return (0);
} */
