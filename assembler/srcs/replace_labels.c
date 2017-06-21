/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:20:25 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:26:12 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_boolean	find_label(char *lbl, int pos, int *args, t_label **label)
{
	t_label			*tmp_label;

	tmp_label = *label;
	while (tmp_label)
	{
		if (ft_strequ(tmp_label->name, lbl))
		{
			*args = tmp_label->pos - pos;
			return (TRUE);
		}
		tmp_label = tmp_label->next;
	}
	return (FALSE);
}

static t_boolean	get_label_in_op(t_op *op, t_label **label)
{
	int				i;

	i = 0;
	while (i < 4)
	{
		if (op->label_args[i])
		{
			if (!find_label(op->label_args[i], op->pos, op->args + i, label))
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_boolean			replace_labels(t_binary *file)
{
	t_op			*tmp;

	tmp = *(file->format.op);
	while (tmp)
	{
		if (!get_label_in_op(tmp, file->format.label))
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}
