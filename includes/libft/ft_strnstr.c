/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:36:47 by ibellash          #+#    #+#             */
/*   Updated: 2023/02/01 13:42:29 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (*(s1 + i) && i < len)
	{
		j = 0;
		while (*(s1 + j + i) == *(s2 + j) && (i + j) < len)
		{
			if (*(s2 + j + 1) == 0)
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
