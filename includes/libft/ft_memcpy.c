/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:30:08 by ibellash          #+#    #+#             */
/*   Updated: 2023/02/01 14:00:20 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	int		i;
	char	*src;
	char	*dest;

	i = 0;
	if (!destptr && !srcptr)
		return (NULL);
	src = (char *)srcptr;
	dest = (char *)destptr;
	while (num-- > 0)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
