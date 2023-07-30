/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:36:54 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/28 17:38:46 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	matrix_len(char **str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	**matrix_dup(char **str, int size)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(sizeof(char *), size + 1);
	i = 0;
	while (i < size)
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	matrix_free(char **str)
{
	int	size;
	int	i;

	i = 0;
	size = matrix_len(str);
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
