/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:21:16 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:26:47 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** State_a:					store champion name
** Transition to state_b:	end of line
*/

void		*state_a(char **str, t_binary *file)
{
	if (lex_str(str, file->header.prog_name, PROG_NAME_LENGTH))
	{
		if (lex_eol(str))
			return (&state_b);
	}
	return (NULL);
}
