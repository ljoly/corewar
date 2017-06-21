/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 14:12:41 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:15:55 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			get_arg_length(int op, int arg_type)
{
	if (arg_type == REG_CODE)
		return (1);
	else if (arg_type == IND_CODE)
		return (2);
	if (op == 1 || op == 2 || op == 6 || op == 7 || op == 8 || op == 13)
		return (4);
	return (2);
}

/*
** Each arg of ops is coded on 3 bits
*/

int			get_available_arg(int id, int arg)
{
	static int		op_tab[16] = {1, 43, 64, 444, 444, 477, 477, 477, 1, 457,
		574, 1, 43, 457, 1, 4};

	if (arg == 1)
		return (op_tab[id - 1] % 10);
	else if (arg == 2)
		return ((op_tab[id - 1] / 10) % 10);
	else if (arg == 3)
		return ((op_tab[id - 1] / 100) % 10);
	return (0);
}

int			get_nbr_arg(int id)
{
	static int		op_tab[16] = {1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1,
		1};

	return (op_tab[id - 1]);
}

/*
** Checking if the op has an OCP: 1 == FALSE, 2 == TRUE
*/

int			get_op_length(int id)
{
	static int		op_tab[16] = {1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1,
		2};

	return (op_tab[id - 1]);
}

char		*get_op_name(int id)
{
	static char		*op_tab[17] = {"live", "ld", "st", "add", "sub", "and",
		"or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork",
		"aff"};

	return (op_tab[id - 1]);
}
