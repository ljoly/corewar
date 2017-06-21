/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_label_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:39:31 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/13 19:59:37 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_boolean		lex_label_arg(char **str, char **name)
{
	if (**str == LABEL_CHAR)
	{
		(*str)++;
		if (lex_label_name(str, name))
			return (TRUE);
		(*str)--;
	}
	return (FALSE);
}
