/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 22:17:27 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:29:19 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** State_e:					on a label, waiting for op or eol
** Transition to state_f:	when an eol was found
** Transition to state_g:	when an op was found
*/

void		*state_e(char **str, t_binary *file)
{
	if (lex_eol(str))
	{
		return (&state_f);
	}
	else if (lex_op(str, file))
	{
		return (state_g(str, file));
	}
	return (NULL);
}
