/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:11:38 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/31 18:14:50 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	init_facing_direction(game);
	
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
