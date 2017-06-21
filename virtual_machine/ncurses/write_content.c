/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:20:04 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 10:25:57 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		legend_two(t_env *env, t_player *pl, int i)
{
	wattrset(env->legend, A_BOLD);
	mvwprintw(env->legend, i, 3, "PLAYER %d: ", pl->number);
	wattrset(env->legend, COLOR_PAIR(pl->colour));
	mvwaddnstr(env->legend, i, 15, pl->nkname, 44);
	wattroff(env->legend, COLOR_PAIR(pl->colour));
	mvwprintw(env->legend, i + 1, 3, "- Last live: %d    ", pl->live_addr);
	mvwprintw(env->legend, i + 2, 3, "- %s: %d    ", LIV, pl->live);
	if (pl->dead > 0)
	{
		wattrset(env->legend, COLOR_PAIR(5));
		mvwprintw(env->legend, i + 2, 48, "[DEAD] ");
	}
	else
	{
		wattron(env->legend, COLOR_PAIR(50) | A_BOLD);
		mvwprintw(env->legend, i + 2, 48, "[alive]");
	}
}

static void		legend_three(t_env *env, int i)
{
	wattrset(env->legend, A_BOLD);
	mvwhline(env->legend, i, 1, '_', 58);
	mvwprintw(env->legend, i + 2, 3, "CYCLE_TO_DIE: %d    ", env->ctd);
	mvwprintw(env->legend, i + 4, 3, "CYCLE_DELTA: %d    ", CYCLE_DELTA);
	mvwprintw(env->legend, i + 6, 3, "NBR_LIVE: %d    ", NBR_LIVE);
	mvwprintw(env->legend, i + 8, 3, "MAX_CHECKS: %d    ", MAX_CHECKS);
	mvwhline(env->legend, 61, 1, '_', 17);
	mvwprintw(env->legend, 61, 20, "WHO JUST SHOUTED LIVE");
	mvwhline(env->legend, 61, 43, '_', 16);
}

void			write_in_legend(t_env *env)
{
	t_list	*play_list;
	int		i;

	box(env->legend, 0, 0);
	wattrset(env->legend, COLOR_PAIR(5));
	mvwprintw(env->legend, 3, 17, "------- COREWAR -------");
	wattrset(env->legend, A_BOLD);
	wattroff(env->legend, COLOR_PAIR(5));
	mvwhline(env->legend, 5, 1, '_', 58);
	mvwprintw(env->legend, 7, 3, "CYCLE: %d          ", env->cycles);
	mvwhline(env->legend, 8, 1, '_', 58);
	wattron(env->legend, A_UNDERLINE | A_BOLD);
	mvwprintw(env->legend, 10, 3, "NUMBER OF PLAYERS: %d", env->n_players);
	wattroff(env->legend, A_UNDERLINE);
	i = 13;
	play_list = env->players_list;
	while (play_list)
	{
		legend_two(env, (t_player*)play_list->content, i);
		i += 5;
		play_list = play_list->next;
	}
	legend_three(env, i);
	wrefresh(env->legend);
}

void			play_with_attributes(t_mem *mem, int i, WINDOW *window)
{
	wattron(window, COLOR_PAIR(mem[i].col));
	if (mem[i].pc == TRUE)
		wattron(window, A_REVERSE);
	if ((mem[i].hi)-- > 0)
		wattron(window, COLOR_PAIR(mem[i].col + 10) | A_BOLD);
	if ((mem[i].li)-- > 0)
		wattron(window, COLOR_PAIR(mem[i].col + 30) | A_BOLD);
}

void			write_in_arena(t_mem *mem, t_env *env)
{
	int		i;
	int		y;
	int		x;

	wattron(env->arena, A_BOLD);
	box(env->arena, 0, 0);
	wstandend(env->arena);
	y = 1;
	i = 0;
	while (y < 70)
	{
		x = 1;
		while (x < 193 && i < MEM_SIZE)
		{
			play_with_attributes(mem, i, env->arena);
			mvwprintw(env->arena, y, x, "%03x", mem[i++].ch);
			wattrset(env->arena, A_NORMAL);
			wattron(env->arena, COLOR_PAIR(0));
			mvwprintw(env->arena, y, x, " ");
			x += 3;
		}
		y++;
	}
	wrefresh(env->arena);
}
