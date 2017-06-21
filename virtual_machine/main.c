/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:11:07 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 21:17:21 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			ft_advance(t_list *proc_list, t_mem *mem)
{
	int			i;
	t_process	*process;

	process = (t_process*)proc_list->content;
	mem[process->pc].pc = FALSE;
	process->mem_index = (process->mem_index + 1) % MEM_SIZE;
	process->pc = (process->pc + 1) % MEM_SIZE;
	mem[process->pc].pc = TRUE;
	process->action = 0;
	process->cycle_timer = 0;
	process->jump = 0;
	i = -1;
	while (++i < 3)
	{
		process->par[i] = 0;
		process->ocp[i] = 0;
	}
}

static void		display_winner(t_env *env)
{
	t_list		*list;
	t_player	*pl;

	list = env->players_list;
	while (list)
	{
		pl = (t_player*)list->content;
		if (pl->number == env->alive)
		{
			if (env->gameover && env->n_players > 1)
				gameover(env, pl->nkname, pl->colour);
			else if (env->graph == -1)
				ft_printf("{cyan}%s%s%s%d\n", W1, pl->nkname, W2, env->alive);
			else
				winner_message(env, pl->nkname, pl->colour);
			return ;
		}
		list = list->next;
	}
	if (env->graph == -1)
		ft_printf("{red}%s\n%s\n%s\n%s{eoc}\n", U1, U2, U3, U4);
	else
		winner_message(env, "", 1);
}

static void		run_a_cycle(t_mem *mem, t_list *p_l, t_list **copy, t_env *env)
{
	t_process *proc;

	proc = (t_process*)p_l->content;
	if (proc->cycle_timer == 0)
		(mem[proc->mem_index].ch > 0 && mem[proc->mem_index].ch <= 16)
			? read_command(mem, p_l) : ft_advance(p_l, mem);
	else if (proc->cycle_timer == 1)
		command_exec(mem, p_l, copy, env);
	else
		proc->cycle_timer -= 1;
	mem[proc->pc].pc = TRUE;
}

static t_list	*game(t_mem *mem, t_list *copy, t_list *proc_list, t_env *env)
{
	t_process	*proc;

	(env->graph != -1) ? initialise_ncurses(env, mem) : 0;
	while (copy && (proc_list = copy) && env->gameover == FALSE
			&& env->live_play > 0)
	{
		while (proc_list)
		{
			proc = (t_process*)proc_list->content;
			if (proc->dead == FALSE)
				run_a_cycle(mem, proc_list, &copy, env);
			proc_list = proc_list->next;
		}
		env->cycles += 1;
		if ((env->cc++) && env->cycles != CYCLE_TO_DIE && env->cc == env->ctd)
			copy = kill_proc(&copy, copy, env, mem);
		if (fdump(mem, env, copy) == 1)
			break ;
		(env->graph != -1) ? graphic(env, mem) : 0;
	}
	return (copy);
}

int				main(int argc, char **argv)
{
	t_list			*proc_list;
	t_mem			mem[MEM_SIZE];
	t_env			*env;

	env = ft_arg_parser(argc, argv);
	proc_list = NULL;
	read_players(env, mem, &proc_list, -1);
	proc_list = game(mem, proc_list, proc_list, env);
	if (env->f_dump < 0)
		display_winner(env);
	(env->graph > 0) ? end_graph(env, mem) : 0;
	free_env(env);
	free_proc_list(proc_list);
	return (0);
}
