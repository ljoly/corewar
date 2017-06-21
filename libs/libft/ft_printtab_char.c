/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:32:21 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/27 14:39:21 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab_char(char **tab)
{
	int		i;
	int		c;
	int		d;

	c = 0;
	d = 0;
	while (tab[d] != NULL)
		d++;
	while (c < d)
	{
		i = 0;
		while (tab[c][i] != '\0')
			ft_putchar(tab[c][i++]);
		ft_putchar('\n');
		c++;
	}
}
