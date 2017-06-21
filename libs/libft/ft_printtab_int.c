/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:40:00 by bdal-can          #+#    #+#             */
/*   Updated: 2017/01/30 17:26:59 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab_int(int **tab, size_t x, size_t y)
{
	size_t	yi;
	size_t	xi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
			ft_putnbr(tab[yi][xi++]);
		ft_putchar('\n');
		yi++;
	}
}
