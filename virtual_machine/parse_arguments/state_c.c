/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:43:54 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:06:37 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

void	*state_c(void *data, void *act_on)
{
	char		*str;
	t_env		*env;
	int			n;

	str = (char*)data;
	env = (t_env*)act_on;
	n = ft_atoi(str);
	if (ft_isalldigits(str) == 0 || n == 0)
	{
		ft_putstr_fd("USAGE ERROR.\n", 2);
		ft_putstr_fd(USAGE_ERR, 2);
		return (NULL);
	}
	env->tmp = n;
	return (&state_d);
}
