/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 12:00:51 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/14 16:37:31 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** State_g:					on an op, waiting for args
** Transition to state_d:	when op's args and eol were found
*/

static t_op			*get_last_op(t_binary *file)
{
	t_op			*tmp;

	tmp = *file->format.op;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void				*state_g(char **str, t_binary *file)
{
	int				arg;
	t_op			*op;

	op = get_last_op(file);
	arg = 1;
	while (arg <= get_nbr_arg(op->op_type))
	{
		if (!lex_op_arg(str, file, op, arg))
			return (NULL);
		if (++arg <= get_nbr_arg(op->op_type))
		{
			lex_blanks(str);
			if (**str != SEPARATOR_CHAR)
				return (NULL);
			(*str)++;
			lex_blanks(str);
		}
	}
	if (lex_eol(str))
		return (&state_d);
	return (NULL);
}
