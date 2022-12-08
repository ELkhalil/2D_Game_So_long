/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:41:10 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 21:37:02 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_walls(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

/* get Player position */
void	find_player(t_map *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp->map[i])
	{
		j = 0;
		while (tmp->map[j])
		{
			if (tmp->map[i][j] == 'P')
			{
				tmp->p_w = i;
				tmp->p_l = j;
			}
			j++;
		}
		i++;
	}
}

static int	check_map_copies(char **cp_map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (cp_map[i])
	{
		j = 0;
		while (cp_map[i][j])
		{
			if (cp_map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_path_valid(t_map *map)
{
	flood_fill_collectibles(map->c_map, map->p_w, map->p_l, map);
	flood_fill_exit(map->c_map2, map->p_w, map->p_l, map);
	if (!check_map_copies(map->c_map, 'C')
		&& !check_map_copies(map->c_map2, 'E'))
		return (1);
	free_array(map->c_map);
	free_array(map->c_map2);
	map->c_map = NULL;
	map->c_map2 = NULL;
	return (0);
}
