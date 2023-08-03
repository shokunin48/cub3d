/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:44:10 by dsas              #+#    #+#             */
/*   Updated: 2023/08/03 15:41:07 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_up(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (game->map[(int)rays->pos_y][(int)(rays->pos_x + \
								rays->dir_x * game->movespeed)] == '0')
		rays->pos_x += rays->dir_x * game->movespeed;
	if (game->map[(int)(rays->pos_y + rays->dir_y * \
							game->movespeed)][(int)rays->pos_x] == '0')
		rays->pos_y += rays->dir_y * game->movespeed;
}

void	key_down(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (game->map[(int)rays->pos_y][(int)(rays->pos_x - \
								rays->dir_x * game->movespeed)] == '0')
		rays->pos_x -= rays->dir_x * game->movespeed;
	if (game->map[(int)(rays->pos_y - rays->dir_y * \
							game->movespeed)][(int)rays->pos_x] == '0')
		rays->pos_y -= rays->dir_y * game->movespeed;
}

void	key_a(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (game->map[(int)rays->pos_y][(int)(rays->pos_x - \
						rays->dir_y * game->movespeed)] == '0')
	rays->pos_x -= rays->dir_y * game->movespeed;
	if (game->map[(int)(rays->pos_y + rays->dir_x * \
				game->movespeed)][(int)rays->pos_x] == '0')
	rays->pos_y += rays->dir_x * game->movespeed;
}

void	key_d(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (game->map[(int)rays->pos_y][(int)(rays->pos_x + \
					rays->dir_y * game->movespeed)] == '0')
	rays->pos_x += rays->dir_y * game->movespeed;
	if (game->map[(int)(rays->pos_y - rays->dir_x * \
				game->movespeed)][(int)rays->pos_x] == '0')
	rays->pos_y -= rays->dir_x * game->movespeed;
}

int	keys(int keycode, t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	rays->oldtime = rays->time;
	rays->time = ft_get_ticks();
	rays->frametime = (rays->time - rays->oldtime) / 1000.0;
	rays->move_speed = rays->frametime * 20.0;
	rays->rot_speed = rays->frametime * 10.0;
	if (keycode == 13)
		key_up(game);
	if (keycode == 1)
		key_down(game);
	if (keycode == 0)
		key_a(game);
	if (keycode == 2)
		key_d(game);
	if (keycode == 124)
		key_right(game);
	if (keycode == 123)
		key_left(game);
	if (keycode == 53)
		close_game(game);
	return (0);
}
