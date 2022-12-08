/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:41:10 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 11:36:58 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_countent_v(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*count flexible data in the map*/
int	counter_data(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/*is the map has the same width on all lines*/
int	is_map_rectangular(char **map)
{
	size_t	map_width;
	int		i;

	i = 1;
	map_width = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != map_width)
			return (0);
		i++;
	}
	return (1);
}

/* check if it is surrounded by walls */
static int	is_top_or_bottom_walls(char *map)
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

int	is_mapclosed(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	if (!is_top_or_bottom_walls(map[0]) || !is_walls(map[i - 1]))
		return (0);
	return (1);
}
