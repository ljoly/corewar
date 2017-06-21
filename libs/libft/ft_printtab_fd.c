/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:40:16 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/27 14:47:32 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printtab_fd(char **tab, int x, int y, int fd)
{
	int		yi;
	int		xi;

	yi = 0;
	while (yi < y)
	{
		xi = 0;
		while (xi < x)
			ft_putchar_fd(tab[yi][xi++], fd);
		ft_putchar_fd('\n', fd);
		yi++;
	}
}
