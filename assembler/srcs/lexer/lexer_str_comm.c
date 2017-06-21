/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_str_comm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 11:43:16 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/14 11:22:11 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_boolean		lex_str_comm(char **str)
{
	char		*tmp;
	int			i;

	tmp = *str;
	i = 0;
	while (*tmp && *tmp == COMMENT_CMD_STRING[i])
	{
		tmp++;
		i++;
	}
	if (!COMMENT_CMD_STRING[i])
	{
		*str = tmp;
		return (TRUE);
	}
	return (FALSE);
}
