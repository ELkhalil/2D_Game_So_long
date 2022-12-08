/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:19:58 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 23:12:27 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*game;
	t_img	*img;

	if (ac != 2)
	{
		write(2, "Error\n <INVALID ARGUMENTS>\n", 28);
		return (0);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		exit(0);
	map_checker(map, av[1]);
	img = malloc(sizeof(t_img));
	game = malloc (sizeof(t_game));
	if (!img || !game)
	{
		clean_memory(map);
		write(2, "Error\n <FAILED TO ALLOCATE MEMORY>\n", 36);
		exit(0);
	}
	so_long(game);
	return (0);
}
