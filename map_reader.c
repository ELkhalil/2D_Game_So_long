/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:44:17 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 20:39:29 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	reading_leak_hundler(int fd, char *buffer, char *container)
{
	if (buffer)
		free(buffer);
	if (container)
		free(container);
	close(fd);
}

static int	is_dotber(char *p)
{
	p += ft_strlen(p) - 4;
	if (ft_strcmp(p, ".ber") == 0)
		return (1);
	return (0);
}

static int	is_new_line(int fd, char *buffer, char *container)
{
	if (buffer[0] == '\n')
	{
		reading_leak_hundler(fd, buffer, container);
		return (0);
	}
	return (1);
}

char	**map_reader(char *map_path)
{
	char	*container;
	char	*buffer;
	char	**map;
	int		fd;

	container = NULL;
	if (!is_dotber(map_path))
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		if (!is_new_line(fd, buffer, container))
			return (NULL);
		container = ft_strjoin(container, buffer);
	}
	if (container[ft_strlen(container) - 1] == '\n')
		return (NULL);
	map = ft_split(container, '\n');
	reading_leak_hundler(fd, buffer, container);
	return (map);
}
