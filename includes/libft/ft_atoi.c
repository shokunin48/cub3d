/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:39:16 by ibellash          #+#    #+#             */
/*   Updated: 2023/07/05 21:16:10 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	result;

	i = 0;
	minus = 1;
	result = 0;
	while (str[i])
	{
		while (ft_iswhitespace(str[i]) == 1)
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				minus = -1;
			i++;
		}
		while (ft_isdigit(str[i]) == 1)
			result = (result * 10) + (str[i++] - '0');
		return (result * minus);
		i++;
	}
	return (0);
}

// int main()
// { 
// 	char *str = "   		\n 12312jhfjd36664";
// 	printf("%d\n", ft_atoi(str));
// }
