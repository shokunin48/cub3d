/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:37:01 by ibellash          #+#    #+#             */
/*   Updated: 2023/01/29 21:13:15 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	if (!destptr && !srcptr)
		return (0);
	if ((size_t)destptr - (size_t)srcptr < num)
	{
		while (num > 0)
		{
			((char *)destptr)[num - 1] = ((char *)srcptr)[num - 1];
			num--;
		}
	}
	else
	{
		ft_memcpy(destptr, srcptr, num);
	}
	return (destptr);
}
