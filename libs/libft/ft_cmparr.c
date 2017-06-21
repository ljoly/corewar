/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:16:59 by bdal-can          #+#    #+#             */
/*   Updated: 2017/05/26 10:42:32 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cmparr(int *tab, int a, int b, int c)
{
	if (tab[0] != a)
		return (0);
	if (tab[1] != b)
		return (0);
	if (tab[2] != c)
		return (0);
	return (1);
}
