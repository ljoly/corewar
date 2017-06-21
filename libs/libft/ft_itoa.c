/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:47:01 by bdal-can          #+#    #+#             */
/*   Updated: 2017/02/27 10:09:14 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static	int		ft_count_digits(long long n)
{
	int		c;

	c = 1;
	if (n < 0)
		c++;
	while (n / 10 != 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char			*ft_itoa(long long n)
{
	int					i;
	unsigned long long	nb;
	char				*str;
	int					c;

	i = 0;
	if (!(str = (char*)malloc(ft_count_digits(n) + 1)))
		return (NULL);
	str[ft_count_digits(n)] = '\0';
	nb = (n < 0) ? -n : n;
	if (n < 0)
		str[i++] = '-';
	c = ft_count_digits(n) - 1;
	while (c >= i)
	{
		str[c--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
