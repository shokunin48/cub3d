/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:04:28 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/28 17:14:02 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_lines(int fd)
{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**read_map(t_game *game, char *map)
{
	char	**res;
	int		fd;
	char	*s;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		throw_error(game, FILE_ERROR);
	res = ft_calloc(sizeof(char *), count_lines(fd) + 1);
	if (!res)
		return (NULL);
	close(fd);
	fd = open(map, O_RDONLY);
	s = get_next_line(fd);
	i = 0;
	while (s)
	{
		res[i] = s;
		s = get_next_line(fd);
		i++;
	}
	res[i] = 0;
	close(fd);
	return (res);
}
