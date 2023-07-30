/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:22:13 by ibellash          #+#    #+#             */
/*   Updated: 2023/02/01 13:08:47 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < 1)
	{
		return (ft_strlen(src));
	}
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
		i = 0;
		while (src[i])
			i++;
	}
	return (i);
}

// int main()
// {
//     char str[20];
// 	char *str1 = "kajkhacjkkackjj27638";
// 	printf("%ld", ft_strlcpy(str, str1, 6));
// 	//int i = ft_strlen(str);
// 	//printf("%d\n", i);
//     //puts(str);
// 	return (0);
// }