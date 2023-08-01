/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:29:55 by ibellash          #+#    #+#             */
/*   Updated: 2023/08/01 20:24:38 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	throw_error(t_game *game, char *message)
{
	//if (game)
	//	free_game(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

//void	free_game(t_game *game)
//{
//	int	i;

//	if (game->imap != NULL)
//	{
//		i = 0;
//		while (i < (int)matrix_len(game->map))
//		{
//			free(game->imap[i]);
//			i++;
//		}
//		free(game->imap);
//	}
//	//free_textures(game);
//	if (game->map)
//		matrix_free(game->map);
//	if (game->win)
//		mlx_destroy_window(game->mlx, game->win);
//	if (game->rays)
//		free(game->rays);
//}

int	close_game(t_game *game)
{
	//free_game(game);
	exit (0);
}
