/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariafer <mariafer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:00:13 by mariafer          #+#    #+#             */
/*   Updated: 2026/06/15 14:00:17 by mariafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_line(int file, char *s)
{
	char		*buffer;
	size_t		lines;
	size_t		counter;

	if (!*s)
		return (0);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	counter = 0;
	lines = 0;
	lines = read(file, buffer, BUFFER_SIZE);
	while (*s && *s != '\n')
	{
		s++;
		counter++;
	}
	return (counter);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		line_counter;

	if (!fd || BUFFER_SIZE < 1)
		return (NULL);
	line_counter = 0;
	line_counter = ft_read_line(fd, line);
}

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;
	int		lines;

	lines = 1;
	fd = open("README.md", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%d->%s\n", lines++, line);
		free(line);
	}
	close(fd);
	return (0);
}