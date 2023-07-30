/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:31:41 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/30 16:55:22 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_game_vars(t_game *game)
{
	game->mlx = mlx_init();
	game->screen_width = 1200;
	game->screen_height = 900;
	game->tex_width = 64;
	game->tex_height = 64;
	game->win = mlx_new_window(game->mlx, game->screen_width, \
									game->screen_height, "Game");
	// game->rays->win = game->win;
	game->texture = (uint32_t **) ft_calloc(sizeof(uint32_t *), 4);
	if (game->texture == NULL)
		return (0);
	return (1);
}

void	init_map_data(t_game *game, char *path)
{
	char	**file_content;

	file_content = read_map(game, path);
	int i = 0;
	int j;
	while(file_content[i])
	{
		j = 0;
		while(file_content[i][j])
		{
			printf("%c", file_content[i][j]);
			j++;
		}
		i++;
	}
	matrix_free(file_content);
}
