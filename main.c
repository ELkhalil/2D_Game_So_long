/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:19:58 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 11:47:15 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map *map;

	if (ac != 2)
	{
		write(2, "Error\n <INVALID ARGUMENTS>\n", 28);
		return (0);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		exit(0);
	if (map_checker(map, av[1]))
		puts("YES VALID !");
	return (0);
}