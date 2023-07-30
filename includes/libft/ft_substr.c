/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:44:54 by ibellash          #+#    #+#             */
/*   Updated: 2023/02/16 22:54:49 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (i < start)
		return (ft_strdup(""));
	if (i - start <= len)
		len = i - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

// int main()
// {
// 	char *str = "skjdjsjcjcjkdckdjc";
// 	puts(ft_substr(str, 3, 8));
// }
