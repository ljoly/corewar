/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:00:59 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 11:12:50 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_bytestointover(int size, int index, t_mem *mem)
{
	int		num;
	int		a;
	int		b;
	int		c;
	int		d;

	num = 0;
	index %= MEM_SIZE;
	if (size == 4)
	{
		a = (mem[index].ch & 0x7f) << 24;
		b = mem[(index + 1) % MEM_SIZE].ch << 16;
		c = mem[(index + 2) % MEM_SIZE].ch << 8;
		d = mem[(index + 3) % MEM_SIZE].ch;
		num = a | b | c | d;
		num = ((mem[index].ch & 0x80) == 0x80) ? num - 2147483648 : num;
	}
	else if (size == 2)
	{
		a = (mem[index].ch & 0x7f) << 8;
		b = mem[(index + 1) % MEM_SIZE].ch;
		num = a | b;
		num = ((mem[index].ch & 0x80) == 0x80) ? num - 32768 : num;
	}
	return (num);
}

void			change_ctd(int lives, int *ctd, t_env *env)
{
	static int	num = 0;

	if (lives >= NBR_LIVE)
	{
		if (*ctd - CYCLE_DELTA > 0)
			*ctd -= CYCLE_DELTA;
		else
			env->gameover = TRUE;
		num = 0;
	}
	else
		num++;
	if (num >= MAX_CHECKS)
	{
		if (*ctd - CYCLE_DELTA > 0)
			*ctd -= CYCLE_DELTA;
		else
			env->gameover = TRUE;
		num = 0;
	}
}

void			reset_lives_and_mark_dead(t_env *env, t_list *proc_list, int l)
{
	t_list	*play_list;

	env->live_play = 0;
	play_list = env->players_list;
	change_ctd(l, &(env->ctd), env);
	while (play_list)
	{
		if (env->cycles != env->ctd)
		{
			if (((t_player*)play_list->content)->dead == 2)
				((t_player*)play_list->content)->dead = 1;
			if (((t_player*)play_list->content)->live == 0)
				((t_player*)play_list->content)->dead = 2;
		}
		((t_player*)play_list->content)->live = 0;
		play_list = play_list->next;
	}
	while (proc_list)
	{
		if (((t_process*)proc_list->content)->dead == FALSE)
			env->live_play++;
		((t_process*)proc_list->content)->living = 0;
		proc_list = proc_list->next;
	}
}

t_list			*kill_proc(t_list **l_h, t_list *tmp, t_env *env, t_mem *mem)
{
	int		lives;

	lives = 0;
	while (tmp)
	{
		lives += ((t_process*)tmp->content)->living;
		if (((t_process*)tmp->content)->living == 0)
		{
			mem[((t_process*)tmp->content)->pc].pc = FALSE;
			((t_process*)tmp->content)->dead = TRUE;
		}
		tmp = tmp->next;
	}
	reset_lives_and_mark_dead(env, *l_h, lives);
	env->cc = 0;
	return (*l_h);
}
