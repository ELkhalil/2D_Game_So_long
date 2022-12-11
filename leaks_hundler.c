/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_hundler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:21:12 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/11 10:40:04 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free (strs);
}

void	clean_memory(t_map *map)
{
	if (map->map)
		free_array(map->map);
	if (map)
		free(map);
}

void	free_game(t_game *game)
{
	clean_memory(game->m_data);
	free(game->img);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
}
