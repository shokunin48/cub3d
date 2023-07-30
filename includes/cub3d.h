/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:13:54 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/28 18:09:30 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../mlx/mlx.h"

# define ARGS_ERROR "Wrong amount of arguments!\n"
# define FILE_ERROR "Given file path is invalid!\n"
# define MAP_ARGS_ERROR "There is some problem with arguments in file!"
# define MAP_ARGS_COLOR_ERROR "Color variable has incorect value!"
# define MAP_WALL_ERROR "Map is not surrounded by walls!\n"
# define MAP_EMPTY_LINES_ERROR "Map has some empty lines inside!\n"
# define MAP_EMPTY_ERROR "There is seems to be no map in file!\n"
# define MAP_PATH_ERROR "Map has no valid path!\n"
# define MAP_COMPONENTS_ERROR "Map doesn't have the player starting \
position, has multiple starting positions or has some invalid characters!\n"
# define SPRITE_ERROR "Couldn't find a sprite. Does it exist?\n"

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ESC			53

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_raycast
{
	void		*mlx;
	void		*win;
}	t_raycast;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_raycast	*rays;
	char		**map;
	int			**imap;
	int			screen_width;
	int			screen_height;
	int			tex_width;
	int			tex_height;
	uint32_t	**texture;
	t_image		wall_north;
	t_image		wall_south;
	t_image		wall_west;
	t_image		wall_east;
	int			floor_color;
	int			ceiling_color;
	int			size_line;
	char		player_direction;
}	t_game;

int		close_game(t_game *game);
int		init_game_vars(t_game *game);
void	throw_error(t_game *game, char *message);
char	**read_map(t_game *game, char *map);
void	init_map_data(t_game *game, char *path);
size_t	matrix_len(char **str);
void	matrix_free(char **str);
void	free_game(t_game *game);

#endif
