/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 12:28:46 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 16:13:52 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** State_d:					waiting for eol, label or op
** Transition to state_e:	when a label was found
** Transition to state_g:	when an op was found
** Potentially a final state
*/

void		*state_d(char **str, t_binary *file)
{
	if (lex_eol(str))
	{
		return (&state_d);
	}
	else if (lex_op(str, file))
	{
		return (state_g(str, file));
	}
	else if (lex_label(str, file))
	{
		lex_blanks(str);
		return (state_e(str, file));
	}
	return (NULL);
}
