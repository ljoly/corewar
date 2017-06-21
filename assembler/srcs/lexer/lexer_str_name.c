/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_str_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:38:16 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/14 10:54:36 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_boolean		lex_str_name(char **str)
{
	char		*tmp;
	int			i;

	tmp = *str;
	i = 0;
	while (*tmp && *tmp == NAME_CMD_STRING[i])
	{
		tmp++;
		i++;
	}
	if (!NAME_CMD_STRING[i])
	{
		*str = tmp;
		return (TRUE);
	}
	return (FALSE);
}
