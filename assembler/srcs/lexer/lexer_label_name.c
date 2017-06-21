/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_label_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:25:40 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:01:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_boolean		lex_label_name(char **str, char **name)
{
	int			i;
	char		*tmp;

	i = 0;
	tmp = *str;
	while (*tmp && ft_strchr(LABEL_CHARS, *tmp))
	{
		tmp++;
		i++;
	}
	if (!i)
		return (FALSE);
	*name = ft_strndup(*str, i);
	*str = tmp;
	return (TRUE);
}
