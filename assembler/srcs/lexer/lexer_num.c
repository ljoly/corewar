/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:56:31 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/15 22:18:30 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_boolean		lex_num(char **str, int *args, int reg)
{
	t_boolean	ret;
	t_boolean	minus;

	ret = FALSE;
	minus = FALSE;
	if (**str == '-')
	{
		if (reg)
			return (FALSE);
		minus = TRUE;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		ret = TRUE;
		(*args) *= 10;
		(*args) += **str - '0';
		(*str)++;
	}
	if (reg && (!*args || *args > REG_NUMBER))
		return (FALSE);
	if (minus)
		*args *= -1;
	return (ret);
}
