/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:39:49 by aelkhali          #+#    #+#             */
/*   Updated: 2022/12/11 14:00:01 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>

/* Get Next Line Settings*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

/* key symbols 
D_key = 2 move right
A_key = 0 move left
W_key = 13 move up
S_key = 1 move down
ES_key = 53 */

/*Map Storage infos*/
typedef struct map_data
{
	char	**map;
	char	**c_map;
	char	**c_map2;
	int		length;
	int		width;
	int		coins;
	int		p_w;
	int		p_l;
}			t_map;

/* Images Storage infos*/
typedef struct image
{
	void	*bg;
	void	*pl;
	void	*wl;
	void	*cc;
	void	*ex;
}			t_img;

/* Game Play infos*/
typedef struct sol_game
{
	t_map	*m_data;
	t_img	*img;
	void	*mlx;
	void	*win;
	int		t_size;
}			t_game;

/* Gameplay functions */
void	so_long(t_game *game);
int		move_player(t_game *game, int flag);
void	add_img_to_win(t_game *game, char **map, int i, int j);

/* Map hundling fucntions */
char	**map_reader(char *map_path);
int		map_checker(t_map *map, char *map_path);

/* parsing functions */
int		is_countent_v(char **map);
int		counter_data(char **map, char c);
int		width_counter(char **map);
int		is_map_rectangular(char **map);
int		is_walls(char *map);
int		is_mapclosed(char **map);
void	find_player(t_map *tmp);
int		is_path_valid(t_map *map);

/*Flood Fill algorithm functions*/
void	flood_fill_collectibles(char	**map, int i, int j, t_map *sct);
void	flood_fill_exit(char	**map, int i, int j, t_map *sct);

/*hundle leaks and clean the memory*/
void	clean_memory(t_map *map);
void	free_game(t_game *game);
void	free_array(char **strs);
void	clear_images(t_game *game);

/* External Helper functions (from libft but with some editing on them )*/
char	*get_next_line(int fd);
void	ft_putstr(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif