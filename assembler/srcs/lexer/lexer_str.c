/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:59:16 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 19:14:03 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_boolean		lex_str(char **str, char *prog_feature, int max_len)
{
	char		*tmp;
	int			i;

	tmp = *str;
	if (*tmp != '\"')
		return (FALSE);
	i = 0;
	tmp++;
	while (i < max_len && *tmp != '\"' && *tmp)
	{
		prog_feature[i] = *tmp;
		i++;
		tmp++;
	}
	if (*tmp != '\"')
		return (FALSE);
	*str = tmp + 1;
	return (TRUE);
}
