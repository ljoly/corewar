/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalldigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:15:03 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/08 13:06:38 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalldigits(char *str)
{
	size_t		i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (++i < ft_strlen(str))
		if (ft_isdigit(str[i]) == 0)
			return (0);
	return (1);
}