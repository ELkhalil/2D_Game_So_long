/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:44:17 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 05:59:11 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_reader(char *map_path)
{
	char	*tmp_map;
	char	*buffer;
	char	**map;
	int		fd;

	tmp_map = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		tmp_map = ft_strjoin(tmp_map, buffer);
	}
	map = ft_split(tmp_map, '\n');
	close(fd);
	free(buffer);
	free(tmp_map);
	return (map);
}
