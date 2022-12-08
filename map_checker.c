/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:36:38 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 07:45:25 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**is_map_readed(char *map_path)
{
	char	**map_check;

	map_check = map_reader(map_path);
	if (!map_check)
	{
		write(2, "Error\n <ISSUE WHILE READING THE MAP>", 28);
		exit(0);
	}
	return (map_check);
}

void	map_checker(t_map *map, char *map_path)
{
	map->map = is_map_readed(map_path);
	map->c_map = is_map_readed(map_path);
	if (!is_countent_v(map->map) || counter_data(map, 'E') != 1
		|| counter_data(map, 'C') < 1 || counter_data(map, 'P') != 1)
	{
		write(2, "Error\n <INVALID MAP COUNTENT>", 30);
		clean_map_memory(map);
		exit(0);
	}
	if (!is_map_rectangular(map->map) || !is_mapclosed(map->map))
	{
		write(2, "Error\n <MAP IS NOT IN A VALID SHAPE>", 37);
		clean_map_memory(map);
		exit(0);
	}
	
	//check map path
}
