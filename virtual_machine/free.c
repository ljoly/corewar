/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:51:55 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 21:21:53 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			count_lives(t_list *proc_list)
{
	int		live;

	live = 0;
	while (proc_list)
	{
		live += ((t_process*)proc_list->content)->living;
		proc_list = proc_list->next;
	}
	return (live);
}

void		gameover(t_env *env, char *name, int col)
{
	if (env->graph < 0)
		ft_printf("{cyan}%s%s%s%d)\n", T2, name, T3, env->alive);
	else if (env->graph > 0)
	{
		wattrset(env->legend, COLOR_PAIR(5));
		mvwprintw(env->legend, 44, 26, "GAMEOVER");
		wattrset(env->legend, A_NORMAL);
		mvwprintw(env->legend, 46, 8, T4);
		mvwprintw(env->legend, 47, 9, T5);
		wattrset(env->legend, COLOR_PAIR(col));
		mvwprintw(env->legend, 49, 28 - ft_strlen(name) / 2 + 2, name);
		wrefresh(env->legend);
	}
}

void		free_env(t_env *env)
{
	t_list *tmp;
	t_list *list;

	list = env->players_list;
	tmp = list;
	while (tmp)
	{
		list = tmp;
		tmp = tmp->next;
		free(((t_player*)list->content)->name);
		free(((t_player*)list->content)->nkname);
		free(((t_player*)list->content)->motto);
		free(list->content);
		free(list);
	}
	free(env);
}

void		free_proc_list(t_list *proc_list)
{
	t_list	*tmp;
	t_list	*list;

	tmp = proc_list;
	while (tmp)
	{
		list = tmp;
		tmp = tmp->next;
		free(list->content);
		free(list);
	}
}

int			fdump(t_mem *mem, t_env *env, t_list *proc_list)
{
	int		i;

	i = -1;
	if (env->cycles == CYCLE_TO_DIE)
	{
		reset_lives_and_mark_dead(env, proc_list, count_lives(proc_list));
		env->cc = 0;
	}
	if (env->f_dump != -1 && env->cycles == env->f_dump)
	{
		while (++i < MEM_SIZE)
		{
			if (i % 32 == 0)
				ft_printf("\n");
			ft_printf("%02x ", mem[i].ch);
		}
		ft_printf("\n\n");
		return (1);
	}
	return (0);
}
