/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:36:38 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 11:47:36 by aelkhali         ###   ########.fr       */
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

void	init_struct(t_map *sct)
{
	find_player(sct);
	sct->width = width_counter(sct->map);
	sct->length = ft_strlen(sct->map[0]);
	sct->coins = counter_data(sct->map, 'C');
	sct->p_coins = 0;
}

int	map_checker(t_map *map, char *map_path)
{
	map->map = is_map_readed(map_path);
	map->c_map = is_map_readed(map_path);
	if (!is_countent_v(map->map) || counter_data(map->map, 'E') != 1
		|| counter_data(map->map, 'C') < 1 || counter_data(map->map, 'P') != 1)
	{
		write(2, "Error\n <INVALID MAP COUNTENT>\n", 31);
		clean_memory(map);
		exit(0);
	}
	if (!is_map_rectangular(map->map) || !is_mapclosed(map->map))
	{
		write(2, "Error\n <MAP IS NOT IN A VALID SHAPE>\n", 38);
		clean_memory(map);
		exit(0);
	}
	init_struct(map);
	if (!is_path_valid(map))
	{
		write(2, "Error\n <THERE IS NO PATH FOR THE PLAYER>\n", 42);
		clean_memory(map);
		exit(0);
	}
	return (1);
}
