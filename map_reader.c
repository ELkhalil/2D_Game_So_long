/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:44:17 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 06:40:41 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	reading_leak_hundler(int fd, char **buffer, char **container)
{
	if (buffer)
		free(buffer);
	if (container)
		free(container);
	close(fd);
}

char	**map_reader(char *map_path)
{
	char	*container;
	char	*buffer;
	char	**map;
	int		fd;

	container = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		if (buffer[0] == '\n')
		{
			reading_leak_hundler(fd, buffer, container);
			return (NULL);
		}
		container = ft_strjoin(container, buffer);
	}
	map = ft_split(container, '\n');
	reading_leak_hundler(fd, buffer, container);
	return (map);
}
