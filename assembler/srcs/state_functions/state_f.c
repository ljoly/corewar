/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 22:22:03 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:43:11 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** State_f:					label on the prev line, waiting for op/label/eol
** Transition to state_d:	when an eol was found
** Transition to state_e:	when a label was found
** Transition to state_g:	when an op was found
** Potentially a final state
*/

void		*state_f(char **str, t_binary *file)
{
	lex_blanks(str);
	if (lex_op(str, file))
	{
		return (state_g(str, file));
	}
	if (lex_eol(str))
	{
		return (&state_d);
	}
	if (lex_label(str, file))
	{
		lex_blanks(str);
		return (state_e(str, file));
	}
	return (NULL);
}
