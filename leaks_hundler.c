/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_hundler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:21:12 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/11 15:27:34 by aelkhali         ###   ########.fr       */
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

void	clear_images(t_game *game)
{
	if (game->img->bg)
		mlx_destroy_image(game->mlx, game->img->bg);
	if (game->img->pl)
		mlx_destroy_image(game->mlx, game->img->bg);
	if (game->img->wl)
		mlx_destroy_image(game->mlx, game->img->bg);
	if (game->img->cc)
		mlx_destroy_image(game->mlx, game->img->bg);
	if (game->img->ex)
		mlx_destroy_image(game->mlx, game->img->bg);
}

void	free_game(t_game *game)
{
	clean_memory(game->m_data);
	free(game->img);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
}
