/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:04:26 by dsas              #+#    #+#             */
/*   Updated: 2023/08/03 15:42:33 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move(int direction, t_game *d)
{
	
	if (direction == 1)
	{
		if ((d->map[(int)(d->rays->pos_x + d->rays->dir_x * d->movespeed)][(int)(d->rays->pos_y)]) == '0')
			{puts("sdf1");
			d->rays->pos_x += d->rays->dir_x * d->movespeed;}
		if ((d->map[(int)(d->rays->pos_x)][(int)(d->rays->pos_y + d->rays->dir_y * d->movespeed)]) == '0')
			{puts("sdf2");
			d->rays->pos_y += d->rays->dir_y * d->movespeed;}
	}
	else if (direction == -1)
	{
		if ((d->map[(int)(d->rays->pos_x - d->rays->dir_x * d->movespeed)][(int)(d->rays->pos_y)]) == '0')
			d->rays->pos_x -= d->rays->dir_x * d->movespeed;
		if ((d->map[(int)(d->rays->pos_x)][(int)(d->rays->pos_y - d->rays->dir_y * d->movespeed)]) == '0')
			d->rays->pos_y -= d->rays->dir_y * d->movespeed;
	}
}

void	rotate(int direction, t_game *d, double rotspeed)
{
	double	old_dir_x;
	double	old_plane_x;

	puts("dsgfds");
	old_dir_x = d->rays->dir_x;
	old_plane_x = d->rays->plane_x;
	if (direction == 1)
	{
		d->rays->dir_x = d->rays->dir_x * cos(-rotspeed) - d->rays->dir_y * sin(-rotspeed);
		d->rays->dir_y = old_dir_x * sin(-rotspeed) + d->rays->dir_y * cos(-rotspeed);
		d->rays->plane_x = d->rays->plane_x * cos(-rotspeed) - d->rays->plane_y * sin(-rotspeed);
		d->rays->plane_y = old_plane_x * sin(-rotspeed) + d->rays->plane_y * cos(-rotspeed);
	}
	else if (direction == -1)
	{
		d->rays->dir_x = d->rays->dir_x * cos(rotspeed) - d->rays->dir_y * sin(rotspeed);
		d->rays->dir_y = old_dir_x * sin(rotspeed) + d->rays->dir_y * cos(rotspeed);
		d->rays->plane_x = d->rays->plane_x * cos(rotspeed) - d->rays->plane_y * sin(rotspeed);
		d->rays->plane_y = old_plane_x * sin(rotspeed) + d->rays->plane_y * cos(rotspeed);
	}
}

int	key_hook(t_game *d)
{
	if (d->key_w)
		key_up(d);
	if (d->key_s)
		key_down(d);
	if (d->key_right)
		rotate(1, d, d->rotspeed);
	if (d->key_left)
		rotate(-1, d, d->rotspeed);
	if (d->key_a)
		key_a(d);
	if (d->key_d)
		key_d(d);
	if (d->key_esc)
		close_game(d);
	return (0);
}

int	key_release(int key, t_game *d)
{
	if (key == W_KEY)
		d->key_w = 0;
	if (key == S_KEY)
		d->key_s = 0;
	if (key == A_KEY)
		d->key_a = 0;
	if (key == D_KEY)
		d->key_d = 0;
	if (key == KEY_ARR_RIGHT)
		d->key_right = 0;
	if (key == KEY_ARR_LEFT)
		d->key_left = 0;
	if (key == ESC_KEY)
		d->key_esc = 0;
	return (0);
}

int	key_press(int key, t_game *d)
{
	if (key == W_KEY)
		d->key_w = 1;
	if (key == S_KEY)
		d->key_s = 1;
	if (key == A_KEY)
		d->key_a = 1;
	if (key == D_KEY)
		d->key_d = 1;
	if (key == KEY_ARR_RIGHT)
		d->key_right = 1;
	if (key == KEY_ARR_LEFT)
		d->key_left = 1;
	if (key == ESC_KEY)
		d->key_esc = 1;
	return (0);
}
