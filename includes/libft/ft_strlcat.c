/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:35:18 by ibellash          #+#    #+#             */
/*   Updated: 2023/02/01 13:10:46 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int		i;
	unsigned long int	len_dst;
	unsigned long int	len_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	while ((len_dst + i) < (size - 1) && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

// int main()
// {
//     char *str = "kajkhacjkkackjj27638";
// 	char *str1 = "kajkhacjkkackjj27638";
// 	printf("%ld", ft_strlcat(str, str1, 6));
// 	//int i = ft_strlen(str);
// 	//printf("%d\n", i);
//     //puts(str);
// 	return (0);
// }
