/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_have_doubles.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:50:39 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/15 15:16:17 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_array_have_doubles(int *arr, int size)
{
	int		c;
	int		i;

	i = -1;
	while (++i < size)
	{
		c = i;
		while (++c < size)
		{
			if (arr[i] == arr[c] && i != c && arr[i])
				return (1);
		}
	}
	return (0);
}
