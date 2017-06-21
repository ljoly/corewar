/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:48:01 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:49:36 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static t_boolean	final_test(void *state)
{
	if (state == &state_c)
		return (TRUE);
	else if (state == &state_d)
		return (TRUE);
	else if (state == &state_e)
		return (TRUE);
	else if (state == &state_f)
		return (TRUE);
	else
		return (FALSE);
}

/*
** Each possible case is defined by a state
** Each state commands a function pointed by a static var
** While running, the machine updates the var with the return value of the
** current state to know what to do next
*/

int					state_machine(int action, char **str, t_binary *file)
{
	static void		*(*state)(char **str, t_binary *file);

	if (action == START)
		state = &(state_initial);
	else if (action == USE)
	{
		state = state(str, file);
		if (state == NULL)
			return (0);
	}
	else if (action == END)
	{
		if (!final_test(state))
			return (0);
	}
	return (1);
}
