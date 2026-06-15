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
#include <stdio.h>

int	ft_read_line(int file, char *s)
{
	char	line;
	int		counter;

	if (!*s)
		return (NULL);
	counter = 0;
	line = read(file, BUFFER_SIZE, counter);
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
