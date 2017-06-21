/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 21:50:53 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:18:39 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

void	*state_e(void *data, void *act_on)
{
	char	*str;
	t_env	*env;

	str = (char*)data;
	env = (t_env*)act_on;
	if (ft_strcmp(str, "-n") == 0)
		return (&state_c);
	else if (ft_iscor(str) == 1)
	{
		ft_addplayer(str, env, 0);
		return (&state_e);
	}
	if (ft_iscor(str) == -1)
	{
		ft_putstr_fd("Can't read file <", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("> \n", 2);
	}
	else
	{
		ft_putstr_fd("USAGE ERROR.\n", 2);
		ft_putstr_fd(USAGE_ERR, 2);
	}
	return (NULL);
}
