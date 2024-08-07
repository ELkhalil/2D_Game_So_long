/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:26:32 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/11 16:10:46 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_imgs_path(t_game *game)
{
	game->img->bg = mlx_xpm_file_to_image(game->mlx, "./textures/bg.xpm",
			&game->t_size, &game->t_size);
	game->img->cc = mlx_xpm_file_to_image(game->mlx, "./textures/cc.xpm",
			&game->t_size, &game->t_size);
	game->img->wl = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->t_size, &game->t_size);
	game->img->ex = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&game->t_size, &game->t_size);
	game->img->pl = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&game->t_size, &game->t_size);
	if (!game->img->bg || !game->img->cc || !game->img->wl
		|| !game->img->ex || !game->img->pl)
	{
		write(2, "Error \n <FAILED TO READ IMAGE !>\n", 34);
		free_game(game);
		exit(0);
	}
}

void	add_img_to_win(t_game *game, char **map, int i, int j)
{
	i = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->img->bg, 0, 0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->pl, j * 65, i * 65);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->cc, j * 65, i * 65);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->wl, j * 65, i * 65);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->ex, j * 65, i * 65);
			j++;
		}
		i++;
	}
}

static int	key_hook_hundler(int key_id, t_game *game)
{
	if (key_id == 53)
	{
		write(1, "Good Bye !\n", 12);
		free_game(game);
		exit(0);
	}
	if (key_id == 13 || key_id == 1 || key_id == 2 || key_id == 0)
		move_player(game, key_id);
	return (1);
}

static int	close_game(t_game *game)
{
	write(1, "Good Bye !\n", 12);
	free_game(game);
	exit(0);
}

void	so_long(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(1, "FAILED TO INITIALIZE THE CONNECTION !!\n", 40);
		free_game(game);
		exit(0);
	}
	game->win = mlx_new_window(game->mlx, game->m_data->length * 65,
			game->m_data->width * 65, "So Long !");
	if (!game->win)
	{
		write(1, "FAILED TO CREATE THE WINDOW !!\n", 32);
		free_game(game);
		exit(0);
	}
	get_imgs_path(game);
	add_img_to_win(game, game->m_data->map, i, j);
	mlx_hook(game->win, 2, 0, key_hook_hundler, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
