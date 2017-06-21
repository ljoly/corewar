/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 20:25:52 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:08:19 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

void	*state_d(void *data, void *act_on)
{
	char	*str;
	t_env	*env;

	str = (char*)data;
	env = (t_env*)act_on;
	if (ft_iscor(str) == -1 || ft_iscor(str) == 0)
	{
		if (ft_iscor(str) == -1)
		{
			ft_putstr_fd("Can't read file <", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(">\n", 2);
		}
		else
		{
			ft_putstr_fd("USAGE ERROR.\n", 2);
			ft_putstr_fd(USAGE_ERR, 2);
		}
		return (NULL);
	}
	ft_addplayer(str, env, 1);
	return (&state_e);
}
