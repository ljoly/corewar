/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:13:16 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/14 16:41:08 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void			ft_add_label(t_label **label, t_label *new)
{
	t_label		*tmp;

	if (*label)
	{
		tmp = *label;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*label = new;
}

t_boolean		lex_label(char **str, t_binary *file)
{
	char		*tmp;
	char		*name;
	t_label		*new_label;

	tmp = *str;
	if (!lex_label_name(&tmp, &name))
		return (FALSE);
	if (*tmp == LABEL_CHAR)
	{
		if (!(new_label = ft_memalloc(sizeof(t_label))))
			ft_err(5);
		new_label->name = name;
		new_label->pos = file->header.prog_size;
		if (!*file->format.label)
			*file->format.label = new_label;
		else
			ft_add_label(file->format.label, new_label);
		*str = tmp + 1;
		return (TRUE);
	}
	free(name);
	return (FALSE);
}
