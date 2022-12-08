/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_hundler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:21:12 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 07:29:37 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    clean_map_memory(t_map *map)
{
    int i;

    i = 0;
    if (map)
    {
        while(map->map[i])
            free(map->map[i++]);
        i = 0;
        while(map->c_map[i])
            free(map->c_map[i++]);
        free(map);
    }
}