/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:08:43 by ibellash          #+#    #+#             */
/*   Updated: 2023/02/01 12:55:23 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	char	*newstr;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s = ft_strlen(s1);
	while (s && ft_strchr(set, s1[s]))
		s--;
	newstr = ft_substr(s1, 0, s + 1);
	return (newstr);
}

// int main ()
// {
// 	char *str = "mdncs,c;als;;allalsa";
// 	char *rem = "md";
// 	puts (ft_strtrim(str, rem));
// }
