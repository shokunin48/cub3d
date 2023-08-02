/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:11:38 by ibellash          #+#    #+#             */
/*   Updated: 2023/08/02 20:23:37 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_facing_direction(t_game *game)
{
	if (game->player_direction == 'E')
	{
		game->rays->dir_x = -1;
		game->rays->plane_y = 0.66;
	}
	if (game->player_direction == 'N')
	{
		game->rays->dir_y = -1;
		game->rays->plane_x = -0.66;
	}
	if (game->player_direction == 'W')
	{
		game->rays->dir_x = 1;
		game->rays->plane_y = -0.66;
	}
	if (game->player_direction == 'S')
	{
		game->rays->dir_y = 1;
		game->rays->plane_x = 0.66;
	}
}

int	init_game_vars(t_game *game)
{
	game->mlx = mlx_init();
	game->screen_width = 1200;
	game->screen_height = 900;
	game->rays->mlx = game->mlx;
	game->tex_width = 64;
	game->tex_height = 64;
	game->movespeed = 0.06;
	game->rotspeed = 0.03;
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_esc = 0;
	game->key_right = 0;
	game->key_left = 0;
	game->win = mlx_new_window(game->mlx, game->screen_width, \
									game->screen_height, "Game");
	game->rays->win = game->win;
	game->texture = (uint32_t **) ft_calloc(sizeof(uint32_t *), 4);
	 if (game->texture == NULL)
	 	return (0);
	return (1);
}

void	init_map_data(t_game *game, char *path)
{
	char	**file_content;

	file_content = read_map(game, path);

	init_map_vars(game, file_content);
	init_map(game, file_content);
	//int i = 0;
	//int j;
	//while(game->map[i])
	//{
	//	j = 0;
	//	while(game->map[i][j])
	//	{
	//		printf("%c", game->map[i][j]);
	//		j++;
	//	}
	//	i++;
	//}
	matrix_free(file_content);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	(void)argv;
	game = ft_calloc(sizeof(t_game), 1);
	game->rays = ft_calloc(sizeof(t_raycast),1);
	if (game == NULL)
		throw_error(game, "Memory allocation!");
	if (argc != 2)
		throw_error(game, ARGS_ERROR);
	if (ft_strlen(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))) != 4)
		throw_error(game, "Wrong extension\n");
	if (!init_game_vars(game))
		throw_error(game, "Memory allocation!");
	init_map_data(game, argv[1]);
	init_facing_direction(game);
	if (!init_textures(game))
		throw_error(game, "Memory allocation!");
	mlx_loop_hook(game->mlx, draw, game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &game);
	mlx_hook(game->win, KEYRELEASE, 1L << 1, &key_release, &game);
	mlx_hook(game->win, 17, 1L << 17, &close_game, &game);
	mlx_loop(game->mlx);
	return (0);
}
