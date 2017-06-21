/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:56:33 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/15 21:55:31 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** State_c:					store description/motto
** Transition to state_d:	end of line
** Potentially a final state
*/

void		*state_c(char **str, t_binary *file)
{
	if (lex_str(str, file->header.comment, COMMENT_LENGTH))
	{
		if (lex_eol(str))
			return (&state_d);
	}
	return (NULL);
}
