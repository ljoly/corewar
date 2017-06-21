/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 13:17:48 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:15:10 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void					ft_add_op(t_op **op, t_op *new)
{
	t_op				*tmp;

	if (*op)
	{
		tmp = *op;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*op = new;
}

static t_boolean		get_op_type(char **str, char *op_type)
{
	int					i;
	int					j;

	i = 1;
	while (i <= NBR_OP)
	{
		j = 0;
		while (get_op_name(i)[j] && get_op_name(i)[j] == (*str)[j])
			j++;
		if (!get_op_name(i)[j] && ((*str)[j] == ' ' || (*str)[j] == '\t'))
		{
			*op_type = i;
			*str += j;
			lex_blanks(str);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_boolean				lex_op(char **str, t_binary *file)
{
	t_op				*new_op;

	if (!(new_op = ft_memalloc(sizeof(t_op))))
		ft_err(5);
	if (get_op_type(str, &(new_op->op_type)))
	{
		new_op->pos = file->header.prog_size;
		if (!*file->format.op)
			*file->format.op = new_op;
		else
			ft_add_op(file->format.op, new_op);
		file->header.prog_size += get_op_length(new_op->op_type);
		return (TRUE);
	}
	free(new_op);
	return (FALSE);
}
