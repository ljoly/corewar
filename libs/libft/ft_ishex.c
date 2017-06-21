/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:11:00 by bdal-can          #+#    #+#             */
/*   Updated: 2017/03/16 15:11:02 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishex(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) < 8)
		return (0);
	if (str[0] == '0' && str[1] == 'x')
		i += 2;
	while (i != 8)
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A'
					&& str[i] <= 'F'))
			i++;
		else
			return (0);
	}
	return (1);
}
