/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:39 by ibellash          #+#    #+#             */
/*   Updated: 2023/02/01 13:51:19 by ibellash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*ft_zero(char *s)
{
	s[0] = '0';
	return (s);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			len;
	long int	nmbr;

	nmbr = n;
	len = ft_count(nmbr);
	if (n <= 0)
	{
		len++;
		nmbr *= -1;
	}
	num = malloc (sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n == 0)
		return (ft_zero(num));
	while (len--)
	{
		num[len] = (nmbr % 10) + '0';
		nmbr = nmbr / 10;
	}
	if (n < 0)
		num[0] = '-';
	return (num);
}

// int main()
// {
// 	printf("%s\n", ft_itoa(-4454));
// }
