/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_op_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 14:55:06 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:27:38 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** Building the OCP, ranking arguments bitwise from left to right
*/

static int			ocp_mask(int arg)
{
	if (arg == 0)
		return (64);
	else if (arg == 1)
		return (16);
	else if (arg == 2)
		return (4);
	else
		return (1);
}

/*
** DIR is a value or label preceded by DIRECT_CHAR
*/

static t_boolean	lex_dir(char **str, t_op *op, int arg)
{
	char			*tmp;
	t_boolean		ret;

	ret = FALSE;
	if (**str == DIRECT_CHAR)
	{
		tmp = *str + 1;
		if (lex_num(&tmp, op->args + arg, 0))
			ret = TRUE;
		else if (lex_label_arg(&tmp, op->label_args + arg))
			ret = TRUE;
		if (ret)
		{
			*str = tmp;
			op->ocp += DIR_CODE * ocp_mask(arg);
		}
	}
	return (ret);
}

/*
** IND is a value or a label stored at the adress of the argument
*/

static t_boolean	lex_ind(char **str, t_op *op, int arg)
{
	char			*tmp;
	t_boolean		ret;

	ret = FALSE;
	tmp = *str;
	if (lex_num(&tmp, op->args + arg, 0))
		ret = TRUE;
	else if (lex_label_arg(&tmp, op->label_args + arg))
		ret = TRUE;
	if (ret)
	{
		*str = tmp;
		op->ocp += IND_CODE * ocp_mask(arg);
	}
	return (ret);
}

/*
** REG is a register: between r1 and rx (x == REG_NUMBER)
*/

static t_boolean	lex_reg(char **str, t_op *op, int arg)
{
	char			*tmp;

	if (**str == 'r')
	{
		tmp = (*str) + 1;
		if (lex_num(&tmp, op->args + arg, 1))
		{
			*str = tmp;
			op->ocp += REG_CODE * ocp_mask(arg);
			return (TRUE);
		}
		return (FALSE);
	}
	return (FALSE);
}

/*
** Getting the correct type of arg and calling the right parsing
** function from lex_func for each arg
*/

t_boolean			lex_op_arg(char **str, t_binary *f, t_op *op, int arg)
{
	static void		*lex_func[3] = {&lex_dir, &lex_ind, &lex_reg};
	static int		mask[3] = {1, 2, 4};
	static int		arg_types[3] = {DIR_CODE, IND_CODE, REG_CODE};
	int				type;

	type = 0;
	while (type < 3)
	{
		if (get_available_arg(op->op_type, arg) & mask[type])
		{
			if (((t_boolean(*)(char**, t_op*, int))lex_func[type])(str, op,
						arg - 1))
			{
				f->header.prog_size += get_arg_length(op->op_type,
						arg_types[type]);
				return (TRUE);
			}
		}
		type++;
	}
	return (FALSE);
}
