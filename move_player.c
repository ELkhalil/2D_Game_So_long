/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:16:27 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/11 13:57:39 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	move_right(t_game *game)
{
	if (ft_strchr("C0E", game->m_data->map
			[game->m_data->p_w][game->m_data->p_l + 1]))
	{
		if (game->m_data->map[game->m_data->p_w]
			[game->m_data->p_l + 1] == 'E' && !game->m_data->coins)
			return (free_game(game), exit(0), 1);
		if (game->m_data->map[game->m_data->p_w]
			[game->m_data->p_l + 1] == 'C')
			game->m_data->coins--;
		if (game->m_data->map[game->m_data->p_w]
			[game->m_data->p_l + 1] == 'E')
			return (1);
		game->m_data->map[game->m_data->p_w][game->m_data->p_l] = '0';
		game->m_data->map[game->m_data->p_w][game->m_data->p_l + 1] = 'P';
		game->m_data->p_l++;
	}
	return (0);
}

static int	move_left(t_game *game)
{
	if (ft_strchr("C0E", game->m_data->map
			[game->m_data->p_w][game->m_data->p_l - 1]))
	{
		if (game->m_data->map[game->m_data->p_w]
			[game->m_data->p_l - 1] == 'E' && !game->m_data->coins)
			return (free_game(game), exit(0), 1);
		if (game->m_data->map[game->m_data->p_w]
			[game->m_data->p_l -1] == 'C')
			game->m_data->coins--;
		if (game->m_data->map[game->m_data->p_w]
			[game->m_data->p_l - 1] == 'E')
			return (1);
		game->m_data->map[game->m_data->p_w][game->m_data->p_l] = '0';
		game->m_data->map[game->m_data->p_w][game->m_data->p_l - 1] = 'P';
		game->m_data->p_l--;
	}
	return (0);
}

static int	move_up(t_game *game)
{
	if (ft_strchr("C0E", game->m_data->map
			[game->m_data->p_w - 1][game->m_data->p_l]))
	{
		if (game->m_data->map[game->m_data->p_w - 1]
			[game->m_data->p_l] == 'E' && !game->m_data->coins)
			return (free_game(game), exit(0), 1);
		if (game->m_data->map[game->m_data->p_w - 1]
			[game->m_data->p_l] == 'C')
			game->m_data->coins--;
		if (game->m_data->map[game->m_data->p_w - 1]
			[game->m_data->p_l] == 'E')
			return (1);
		game->m_data->map[game->m_data->p_w][game->m_data->p_l] = '0';
		game->m_data->map[game->m_data->p_w -1][game->m_data->p_l] = 'P';
		game->m_data->p_w--;
	}
	return (0);
}

static int	move_down(t_game *game)
{
	if (ft_strchr("C0E", game->m_data->map
			[game->m_data->p_w + 1][game->m_data->p_l]))
	{
		if (game->m_data->map[game->m_data->p_w + 1]
			[game->m_data->p_l] == 'E' && !game->m_data->coins)
			return (free_game(game), exit(0), 1);
		if (game->m_data->map[game->m_data->p_w + 1][game->m_data->p_l] == 'C')
			game->m_data->coins--;
		if (game->m_data->map[game->m_data->p_w + 1]
			[game->m_data->p_l] == 'E')
			return (1);
		game->m_data->map[game->m_data->p_w][game->m_data->p_l] = '0';
		game->m_data->map[game->m_data->p_w + 1][game->m_data->p_l] = 'P';
		game->m_data->p_w++;
	}
	return (0);
}

int	move_player(t_game *game, int flag)
{
	static int	move;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (flag == 2)
		move_right(game);
	else if (flag == 0)
		move_left(game);
	else if (flag == 13)
		move_up(game);
	else if (flag == 1)
		move_down(game);
	add_img_to_win(game, game->m_data->map, i, j);
	move++;
	ft_putstr("Move : ");
	ft_putnbr_fd(move, 1);
	write(1, "\n", 1);
	return (1);
}
