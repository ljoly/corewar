/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4bytestoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:06:26 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 15:10:01 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bytestointover(int size, int index, unsigned char *mem)
{
	int		num;
	int		a;
	int		b;
	int		c;
	int		d;

	num = 0;
	index %= MEM_SIZE;
	if (size == 4)
	{
		a = mem[index] << 24;
		b = mem[(index + 1) % MEM_SIZE] << 16;
		c = mem[(index + 2) % MEM_SIZE] << 8;
		d = mem[(index + 3) % MEM_SIZE];
		num = a | b | c | d;
	}
	else if (size == 2)
	{
		a = mem[index] << 8;
		b = mem[(index + 1) % MEM_SIZE];
		num = a | b;
	}
	return (num);
}
