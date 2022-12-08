/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:41:10 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 12:29:57 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*count the width of the map*/
int	width_counter(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int is_walls(char *map)
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

/*Checking the map path if valid*/
static void	flood_fill(char	**map, int i, int j, t_map *sct)
{
	if (i < 0 || i >= sct->width || j < 0
		|| j >= sct->length || map[i][j] == '1')
		return ;
	if (map[i][j] == 'C' || map[i][j] == 'E')
		if (map[i][j] == 'C')
			sct->p_coins += 1;
	map[i][j] = '1';
	flood_fill(sct->c_map, i + 1, j, sct);
	flood_fill(sct->c_map, i - 1, j, sct);
	flood_fill(sct->c_map, i, j + 1, sct);
	flood_fill(sct->c_map, i, j - 1, sct);
}

static int	re_check_cp_map(char **cp_map)
{
	int i;
	int	j;

	i = 0;
	while (cp_map[i])
	{
		j = 0;
		while (cp_map[i][j])
		{
			if (cp_map[i][j] != '1')
				if (cp_map[i][j] != '0')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_path_valid(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	flood_fill(map->c_map, map->p_w, map->p_l, map);
	if (map->p_coins == map->coins && re_check_cp_map(map->c_map))
		return (1);
	free_array(map->c_map);
	map->c_map = NULL;
	return (0);
}
