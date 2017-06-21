/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_endian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 16:50:30 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:13:34 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

unsigned int		little_to_big_endian(unsigned int n)
{
	unsigned char	*s;
	unsigned int	res;

	s = (unsigned char*)&n;
	res = 0 | (unsigned int)s[0] << 24 | (unsigned int)s[1] << 16 |
		(unsigned int)s[2] << 8 | (unsigned int)s[3];
	return (res);
}
