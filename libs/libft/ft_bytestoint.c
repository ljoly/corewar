/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4bytestoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:06:26 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:10:27 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bytestoint(unsigned char *bytes, int size)
{
	int		num;

	num = 0;
	if (size == 4)
		num = (bytes[0] << 24) | (bytes[1] << 16)
			| (bytes[2] << 8) | (bytes[3]);
	else if (size == 2)
		num = (bytes[0] << 8) | bytes[3];
	return (num);
}
