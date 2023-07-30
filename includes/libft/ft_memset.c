/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:35:11 by ibellash          #+#    #+#             */
/*   Updated: 2022/12/28 20:19:57 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)destination;
	while (n > 0)
	{
		dest[i++] = c;
		n--;
	}
	return (dest);
}
