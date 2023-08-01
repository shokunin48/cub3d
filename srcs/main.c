/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:11:38 by ibellash          #+#    #+#             */
/*   Updated: 2023/08/01 15:00:03 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_game_vars(t_game *game)
{
	game->mlx = mlx_init();
	game->screen_width = 1200;
	game->screen_height = 900;
	//game->rays->mlx = game->mlx;
	game->tex_width = 64;
	game->tex_height = 64;
	game->win = mlx_new_window(game->mlx, game->screen_width, \
									game->screen_height, "Game");
	//game->rays->win = game->win;
	//game->texture = (uint32_t **) ft_calloc(sizeof(uint32_t *), 4);
	// if (game->texture == NULL)
	// 	return (0);
	return (1);
}

void	init_map_data(t_game *game, char *path)
{
	char	**file_content;

	file_content = read_map(game, path);

	init_map_vars(game, file_content);
	init_map(game, file_content);
	int i = 0;
	int j;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			printf("%c", game->map[i][j]);
			j++;
		}
		i++;
	}
	matrix_free(file_content);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	(void)argv;
	game = ft_calloc(sizeof(t_game), 1);
	if (game == NULL)
		throw_error(game, "Memory allocation!");
	if (argc != 2)
		throw_error(game, ARGS_ERROR);
	if (!init_game_vars(game))
		throw_error(game, "Memory allocation!");
	init_map_data(game, argv[1]);
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
