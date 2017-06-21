/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:46:16 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 22:18:17 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

int				ft_addplayer(char *str, t_env *env, int tmp)
{
	static int	col = 1;
	t_player	player;
	t_list		*new;

	player.name = ft_strdup(str);
	player.number = (tmp) ? env->tmp : 0;
	player.motto = NULL;
	player.nkname = NULL;
	player.i = -1;
	player.size = 0;
	player.live = 0;
	player.dead = 0;
	player.live_addr = 0;
	player.colour = col;
	env->tmp = -1;
	new = ft_lstnew(((void*)&player), sizeof(t_player));
	if (env->players_list == NULL)
		env->players_list = new;
	else
		ft_lstaddend(&(env->players_list), new);
	col++;
	return (1);
}

int				ft_iscor(char *str)
{
	int		fd;
	char	*copy;
	int		i;

	copy = str;
	i = ft_strlen(str) - 4;
	str += i;
	if (ft_strcmp(str, ".cor") != 0)
		return (0);
	fd = open(copy, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (1);
}

static void		print_error(int a, char *str)
{
	if (a < 0)
	{
		ft_putstr_fd(CT, 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(">\n", 2);
	}
	else
	{
		ft_putstr_fd(UE, 2);
		ft_putstr_fd(USAGE_ERR, 2);
	}
}

void			*state_a(void *data, void *act_on)
{
	char	*str;
	t_env	*env;
	int		a;

	str = (char*)data;
	env = (t_env*)act_on;
	if (ft_strcmp(str, "-dump") == 0 && env->f_dump == -1 && env->graph < 0)
		return (&state_b);
	else if (ft_strcmp(str, "-v") == 0 && env->graph == -1
			&& (env->graph = 1) && env->f_dump < 0)
		return (&state_a);
	else if (ft_strcmp(str, "-p") == 0 && env->graph == -1
			&& (env->graph = 1) && env->f_dump < 0)
	{
		env->one_by_one = 1;
		return (&state_a);
	}
	else if (ft_strcmp(str, "-n") == 0)
		return (&state_c);
	else if ((a = ft_iscor(str)) == 1 && ft_addplayer(str, env, 0))
		return (&state_e);
	print_error(a, str);
	return (NULL);
}
