/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:44:25 by bdal-can          #+#    #+#             */
/*   Updated: 2017/05/04 17:25:48 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_good_char(char c, int base)
{
	if (base <= 10)
	{
		if (c >= '0' && c <= '9')
			return (1);
	}
	else
	{
		if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'A' + base - 10))
			return (1);
	}
	return (0);
}

int		ft_atoi_base(char *str, int base)
{
	int		n;
	int		i;
	int		neg;

	i = 0;
	n = 0;
	if (base < 2 || base > 16 || !str)
		return (0);
	neg = 1;
	while (ft_isspace(*str))
		str++;
	neg = (str[i] == '-') ? -1 : 1;
	(str[i] == '-' || str[i] == '+') ? i++ : i;
	if (str[0] == '0' && ((base == 16 && str[1] == 'x')
			|| (base == 2 && str[1] == 'b')))
		i += 2;
	while (ft_good_char(str[i], base) == 1)
	{
		if (str[i] - 'A' >= 0)
			n = n * base + (str[i] - 'A' + 10);
		else
			n = n * base + (str[i] - '0');
		i++;
	}
	return (n * neg);
}
