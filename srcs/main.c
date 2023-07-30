/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:11:38 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/29 19:21:18 by ibellash         ###   ########.fr       */
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
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
