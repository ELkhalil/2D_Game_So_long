/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:41:10 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 07:53:29 by aelkhali         ###   ########.fr       */
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

/* get Player position */
static void	find_player(t_map *tmp)
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
				tmp->p_x = tmp[i];
				tmp->p_y = tmp[j];
			}
			j++;
		}
		i++;
	}
		
}

/*Checking the map path if valid*/
static void	flood_fill(char **av, int i, int j)
{
	/* base case */
	

}

int	is_path_valid(t_map *map)
{
	flood_fill(map->c_map, )
}
