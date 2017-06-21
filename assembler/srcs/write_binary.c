/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:01:03 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/15 20:26:24 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
** Writting a value regarding its size in byte(s)
*/

static void			write_value(int nb, int fd, int size)
{
	char			v;

	if (size == 4)
	{
		v = (nb & 0xff000000) / 0x1000000;
		write(fd, &v, 1);
		v = (nb & 0xff0000) / 0x10000;
		write(fd, &v, 1);
	}
	if (size >= 2)
	{
		v = (nb & 0xff00) / 0x100;
		write(fd, &v, 1);
	}
	v = nb & 0xff;
	write(fd, &v, 1);
}

static void			write_param(t_op *op, int fd, int arg)
{
	if ((op->ocp & 0xc0) / 0x40 == DIR_CODE)
		write_value((op->args)[arg], fd,
				get_arg_length(op->op_type, DIR_CODE));
	else if ((op->ocp & 0xc0) / 0x40 == IND_CODE)
		write_value((op->args)[arg], fd, 2);
	else if ((op->ocp & 0xc0) / 0x40 == REG_CODE)
		write_value((op->args)[arg], fd, 1);
}

/*
** Writting op_code, ocp, and isolating args with ocp *= 4
*/

static void			write_op(t_op *op, int fd)
{
	int				arg;

	write(fd, &(op->op_type), 1);
	if (get_op_length(op->op_type) == 2)
		write(fd, &(op->ocp), 1);
	arg = 0;
	while (arg < get_nbr_arg(op->op_type))
	{
		write_param(op, fd, arg);
		op->ocp *= 4;
		arg++;
	}
}

static void			write_prog(t_op **op, int fd)
{
	t_op			*tmp;

	tmp = *op;
	while (tmp)
	{
		write_op(tmp, fd);
		tmp = tmp->next;
	}
}

void				write_binary(t_binary *file, int fd)
{
	int				m;
	int				s;

	m = file->header.magic;
	file->header.magic = little_to_big_endian(m);
	s = file->header.prog_size;
	file->header.prog_size = little_to_big_endian(s);
	write(fd, (char *)(&(file->header)), sizeof(t_header));
	write_prog(file->format.op, fd);
}
