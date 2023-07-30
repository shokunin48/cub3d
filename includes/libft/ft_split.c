/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:08:36 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/07 17:58:14 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nmbr_words(char *s, char c)
{
	int		reset;
	size_t	i;

	reset = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && reset == 0)
		{
			i++;
			reset = 1;
		}
		else if (*s == c)
			reset = 0;
		s++;
	}
	return (i);
}

static	char	*word_building(char const *str, char delimeter, int *start)
{
	char	*newstr;
	int		i;

	i = 0;
	while (str[i + *start] != delimeter)
	{
		if (str[i + *start] == '\0')
			break ;
		i++;
	}
	newstr = ft_substr(str, *start, i);
	*start += i + 1;
	return (newstr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	int		start;
	char	**arrstr;

	j = nmbr_words((char *)s, c);
	len = 0;
	start = 0;
	arrstr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!s || !arrstr)
		return (NULL);
	i = 0;
	while (i != j)
	{
		if (s[start] == c)
			start++;
		else
			arrstr[i++] = word_building(s, c, &start);
	}
	arrstr[i] = 0;
	return (arrstr);
}

// int main()
// {
// 	int i = 0;
// 	const char *str = "  scsce9     sc csdcdede edef  ";
// 	char c = ' ';
// 	char **new;
// 	new = ft_split(str, c);
// 	while (new[i] != NULL)
// 	{
// 		puts(new[i]);
// 		i++;
// 	}
// }
