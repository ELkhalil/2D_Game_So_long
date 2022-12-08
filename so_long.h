/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:39:49 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/08 05:58:37 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

/* Get Next Line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef struct map_infos
{
	char	**map;
}			t_map;

/* Map hundling fucntions */
char	**map_reader(char *map_path);

/* utils for my project */


/* External Helper functions (from libft but with some editing on them )*/
char	*get_next_line(int fd);
void	ft_putstr(char *str);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_strcmp(char *s1, char *s2);

#endif