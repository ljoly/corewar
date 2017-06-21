/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:55:13 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/07 17:02:31 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_pos_power(int value, int power)
{
	int					i;
	unsigned long long	nb;

	if (value < 0)
		value = -value;
	nb = value;
	if (power == 0)
		return (1);
	i = 1;
	while (i < power)
	{
		nb *= nb;
		i++;
	}
	return (nb);
}
