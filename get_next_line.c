/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egerin <egerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:45:30 by egerin            #+#    #+#             */
/*   Updated: 2024/11/30 15:46:57 by egerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ssize_t read (int fd, void *buf, size_t count);

#include "get_next_line.h"

char	*ft_read(int fd)
{
	int		bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
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
