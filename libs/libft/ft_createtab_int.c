/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createtab_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 12:28:19 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/27 14:12:53 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_createtab_int(size_t x, size_t y)
{
	size_t	xi;
	size_t	yi;
	int		**tab;

	if (!(tab = (int**)malloc(sizeof(int*) * y + 1)))
		return (NULL);
	yi = 0;
	while (yi < y)
	{
		if (!(tab[yi] = (int*)malloc(sizeof(int) * x)))
		{
			free(tab);
			return (NULL);
		}
		xi = 0;
		while (xi < x)
			tab[yi][xi++] = 0;
		yi++;
	}
	tab[yi] = NULL;
	return (tab);
}
