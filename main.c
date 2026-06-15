/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariafer <mariafer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 15:17:45 by mariafer          #+#    #+#             */
/*   Updated: 2026/06/15 15:17:46 by mariafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"

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
