/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:33:00 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/14 12:34:36 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** State_b:					looking for COMMENT_CMD_STRING
** Transition to state_c:	when NAME_CMD_STRING was found
*/

void		*state_b(char **str, t_binary *file)
{
	if (lex_eol(str))
		return (&state_b);
	else if (lex_str_comm(str))
	{
		if (lex_blanks(str))
			return (state_c(str, file));
	}
	return (NULL);
}
