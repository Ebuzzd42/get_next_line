/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:45:30 by egerin            #+#    #+#             */
/*   Updated: 2024/12/02 18:56:26 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ssize_t read (int fd, void *buf, size_t count);

#include "get_next_line.h"

char	*ft_read(int fd)
{
	int		bytes;
	char	*buffer;
	int		i;

	// char		*tmp;
	// static char	*str;
	buffer = (char *)malloc(sizeof(char) * (3 + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, 3);
	// i = 0;
	// bytes = 1;
	/*while (bytes != 0)
	{
		bytes = read(fd, buffer, 3);
		str = ft_strjoin(tmp, buffer);
	}*/
	if (bytes <= 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*str;

	str = ft_read(fd);
	return (str);
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*gnl;
	int		count;

	count = 0;
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, gnl);
		free(gnl);
		gnl = NULL;
	}
	close(fd);
	return (0);
}
