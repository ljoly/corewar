/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 17:27:51 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:10:16 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_parser.h"

static t_env	*ft_initialise_env(t_env *env, int count)
{
	if (!(env = (t_env*)malloc(sizeof(t_env))))
	{
		ft_putstr_fd("Malloc error!\n", 2);
		exit(0);
	}
	env->players_list = NULL;
	env->f_dump = -1;
	env->graph = -1;
	env->one_by_one = FALSE;
	env->tmp = -1;
	env->n_players = count;
	env->live_play = env->n_players;
	env->gameover = FALSE;
	env->cc = 0;
	env->alive = 0;
	env->cycles = 0;
	env->ctd = CYCLE_TO_DIE;
	return (env);
}

void			ft_free_env_exit(t_env *env, char *message)
{
	t_list *tmp;
	t_list *list;

	if (ft_strcmp(message, "usage_error") == 0)
	{
		ft_putstr_fd("USAGE ERROR.\n", 2);
		ft_putstr_fd(USAGE_ERR, 2);
	}
	list = env->players_list;
	tmp = list;
	while (tmp)
	{
		list = tmp;
		tmp = tmp->next;
		free(((t_player*)list->content)->name);
		free(list->content);
		free(list);
	}
	free(env);
	exit(0);
}

static int		ft_countplayers(int ac, char **av)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (++i < ac)
		if (ft_iscor(av[i]) == 1)
			count++;
	if (count == 0 || count > MAX_PLAYERS)
		return (0);
	return (count);
}

int				ft_assign_playernumber(t_list *list, int n, int i, t_list *copy)
{
	int		*arr;

	arr = (int*)malloc(sizeof(int) * n);
	while (++i < n)
		arr[i] = 0;
	i = 0;
	while (list)
	{
		if (((t_player*)(list->content))->number != 0)
			arr[i++] = ((t_player*)(list->content))->number;
		list = list->next;
	}
	i = 1;
	while (copy)
	{
		while (ft_isinarray(arr, i, n) == 1)
			i++;
		if (((t_player*)(copy->content))->number == 0)
			((t_player*)(copy->content))->number = i++;
		copy = copy->next;
	}
	if (ft_array_have_doubles(arr, n) == 1)
		return (0);
	free(arr);
	return (1);
}

t_env			*ft_arg_parser(int ac, char **av)
{
	t_env		*env;
	int			i;

	env = NULL;
	if (ac == 1 || (ac == 2 && !ft_strcmp(av[1], "-h")))
		ft_usage();
	state_machine(NEW, NULL, NULL);
	if (ft_countplayers(ac, av) == 0)
	{
		ft_putstr_fd("USAGE ERROR.\n", 2);
		ft_putstr_fd(USAGE_ERR, 2);
		exit(0);
	}
	env = ft_initialise_env(env, ft_countplayers(ac, av));
	i = 1;
	while (i < ac)
		if (state_machine(USE, (void*)(av[i++]), (void*)env) == 1)
			ft_free_env_exit(env, "");
	if (state_machine(END, NULL, NULL))
		ft_free_env_exit(env, "usage_error");
	if (ft_assign_playernumber(env->players_list, env->n_players,
				-1, env->players_list) == 0)
		ft_free_env_exit(env, "usage_error");
	return (env);
}
