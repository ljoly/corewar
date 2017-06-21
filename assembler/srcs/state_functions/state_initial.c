/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_initial.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:33:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:45:50 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
** State_init:				looking for NAME_CMD_STRING
** Transition to state_a:	when NAME_CMD_STRING was found
*/

void		*state_initial(char **str, t_binary *file)
{
	if (lex_eol(str))
	{
		return (&state_initial);
	}
	else if (lex_str_name(str))
	{
		if (lex_blanks(str))
			return (state_a(str, file));
	}
	return (NULL);
}
