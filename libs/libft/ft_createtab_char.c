/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createtab_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:32:20 by bdal-can          #+#    #+#             */
/*   Updated: 2017/04/20 17:14:41 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_createtab_char(int x, int y)
{
	int		xi;
	int		yi;
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * y + 1)))
		return (NULL);
	yi = 0;
	while (yi < y)
	{
		if (!(tab[yi] = (char*)malloc(sizeof(char) * x + 1)))
		{
			free(tab);
			return (NULL);
		}
		xi = 0;
		while (xi < x)
			tab[yi][xi++] = '\0';
		tab[yi][xi] = '\0';
		yi++;
	}
	tab[yi] = NULL;
	return (tab);
}
