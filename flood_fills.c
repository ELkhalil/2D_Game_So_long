/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fills.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:23:36 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 21:35:11 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_collectibles(char **map, int i, int j, t_map *sct)
{
	if (i < 0 || i >= sct->width || j < 0
		|| j >= sct->length || map[i][j] == '1' || map[i][j] == 'E')
		return ;
	map[i][j] = '1';
	flood_fill_collectibles(sct->c_map, i + 1, j, sct);
	flood_fill_collectibles(sct->c_map, i - 1, j, sct);
	flood_fill_collectibles(sct->c_map, i, j + 1, sct);
	flood_fill_collectibles(sct->c_map, i, j - 1, sct);
}

void	flood_fill_exit(char **map, int i, int j, t_map *sct)
{
	if (i < 0 || i >= sct->width || j < 0
		|| j >= sct->length || map[i][j] == '1')
		return ;
	map[i][j] = '1';
	flood_fill_exit(sct->c_map2, i + 1, j, sct);
	flood_fill_exit(sct->c_map2, i - 1, j, sct);
	flood_fill_exit(sct->c_map2, i, j + 1, sct);
	flood_fill_exit(sct->c_map2, i, j - 1, sct);
}
