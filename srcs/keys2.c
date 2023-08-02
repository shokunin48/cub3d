/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:45:30 by dsas              #+#    #+#             */
/*   Updated: 2023/08/02 17:45:47 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_left(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	rays->old_dir_x = rays->dir_x;
	rays->dir_x = rays->dir_x * cos(rays->rot_speed) - \
									rays->dir_y * sin(rays->rot_speed);
	rays->dir_y = rays->old_dir_x * sin(rays->rot_speed) + \
									rays->dir_y * cos(rays->rot_speed);
	rays->old_plane_x = rays->plane_x;
	rays->plane_x = rays->plane_x * cos(rays->rot_speed) - \
									rays->plane_y * sin(rays->rot_speed);
	rays->plane_y = rays->old_plane_x * sin(rays->rot_speed) + \
									rays->plane_y * cos(rays->rot_speed);
}

void	key_right(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	rays->old_dir_x = rays->dir_x;
	rays->dir_x = rays->dir_x * cos(-rays->rot_speed) - \
									rays->dir_y * sin(-rays->rot_speed);
	rays->dir_y = rays->old_dir_x * sin(-rays->rot_speed) + \
									rays->dir_y * cos(-rays->rot_speed);
	rays->old_plane_x = rays->plane_x;
	rays->plane_x = rays->plane_x * cos(-rays->rot_speed) - \
									rays->plane_y * sin(-rays->rot_speed);
	rays->plane_y = rays->old_plane_x * sin(-rays->rot_speed) + \
									rays->plane_y * cos(-rays->rot_speed);
}
