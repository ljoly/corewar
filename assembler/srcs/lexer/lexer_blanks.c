/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_blanks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:59:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/12 11:31:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_boolean		lex_blanks(char **str)
{
	t_boolean	ret;

	ret = FALSE;
	while (**str == ' ' || **str == '\t')
	{
		ret = TRUE;
		(*str)++;
	}
	return (ret);
}