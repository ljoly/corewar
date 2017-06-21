/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:25:49 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/27 14:39:48 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printtab(char **tab, int x, int y)
{
	int		yi;
	int		xi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
			ft_putchar(tab[yi][xi++]);
		ft_putchar('\n');
		yi++;
	}
}
