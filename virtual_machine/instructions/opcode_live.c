/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_live.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:41:37 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 10:59:45 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

char	*update_living_info(t_env *env, int n)
{
	t_list		*play_list;
	t_player	*player;

	play_list = env->players_list;
	while (play_list)
	{
		player = (t_player*)play_list->content;
		if (player->number == n)
		{
			player->live += 1;
			player->live_addr = env->cycles + 1;
			return (player->nkname);
		}
		play_list = play_list->next;
	}
	return ("");
}

void	living_message(char *name, int n, t_env *env, int col)
{
	int			x;

	if (env->graph == -1)
		ft_printf("%s (PLAYER %d) is alive!!!\n", name, n);
	else
	{
		wattrset(env->legend, COLOR_PAIR(col));
		mvwhline(env->legend, 63, 1, ' ', 58);
		x = 28 - (ft_strlen(name) / 2);
		x = (x < 3) ? 3 : x;
		mvwaddnstr(env->legend, 63, x, name, 54);
		wattroff(env->legend, A_BOLD | COLOR_PAIR(col));
		wattrset(env->legend, A_NORMAL);
	}
}

int		opcode_live(t_list *proc_list, t_list **l_head, t_env *env, t_mem *mem)
{
	int			n;
	t_list		*copy;
	t_process	*process;

	process = (t_process*)proc_list->content;
	n = process->par[0];
	copy = *l_head;
	while (copy)
	{
		if (((t_process*)copy->content)->process_number == n)
		{
			living_message(update_living_info(env, n),
					((t_process*)copy->content)->process_number,
					env, ((t_process*)copy->content)->col);
			((t_process*)copy->content)->living += 1;
			env->alive = ((t_process*)copy->content)->process_number;
			mem[process->pc].li = 30;
			return (1);
		}
		copy = copy->next;
	}
	return (0);
}
