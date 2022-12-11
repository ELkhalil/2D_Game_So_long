/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:44:17 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/11 21:26:32 by aelkhali         ###   ########.fr       */
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
	char	**spl_path;
	int		i;

	i = 0;
	spl_path = ft_split(p, '/');
	while (spl_path[i + 1])
		i++;
	if (ft_strlen(spl_path[i]) <= 4)
	{
		free_array(spl_path);
		return (0);
	}
	free_array(spl_path);
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

char	**map_reader(char *map_path, char **map, int fd)
{
	char	*container;
	char	*buffer;

	container = NULL;
	if (!is_dotber(map_path))
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = get_next_line(fd);
	if (!buffer)
		return (NULL);
	while (buffer)
	{
		if (!is_new_line(fd, buffer, container))
			return (NULL);
		container = ft_strjoin(container, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (container[ft_strlen(container) - 1] == '\n')
		return (NULL);
	map = ft_split(container, '\n');
	reading_leak_hundler(fd, buffer, container);
	return (map);
}
