/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:19:49 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 13:45:29 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

WINDOW		*create_newwin(int height, int width, int starty, int startx)
{
	WINDOW	*local_win;

	local_win = newwin(height, width, starty, startx);
	wattrset(local_win, A_BOLD);
	wrefresh(local_win);
	return (local_win);
}

void		destroy_win(WINDOW *local_win)
{
	refresh();
	wrefresh(local_win);
	wclear(local_win);
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}

void		winner_message(t_env *env, char *name, int col)
{
	mvwhline(env->legend, 63, 1, ' ', 58);
	if (ft_strcmp(name, "") != 0)
	{
		mvwhline(env->legend, 43, 1, '*', 58);
		wattrset(env->legend, COLOR_PAIR(5));
		mvwprintw(env->legend, 45, 18, "...AND THE WINNER IS");
		wattrset(env->legend, COLOR_PAIR(col));
		if (28 - (ft_strlen(name) / 2) < 3)
			mvwprintw(env->legend, 47, 3, name);
		else
			mvwprintw(env->legend, 47, 28 - ft_strlen(name) / 2 + 2, name);
	}
	else
	{
		wattrset(env->legend, COLOR_PAIR(5));
		mvwprintw(env->legend, 45, 15, U1);
		mvwprintw(env->legend, 46, 5, U2);
		mvwprintw(env->legend, 47, 5, U3);
		mvwprintw(env->legend, 48, 17, U4);
	}
	wattrset(env->legend, A_NORMAL);
	wrefresh(env->legend);
}

void		end_graph(t_env *env, t_mem *mem)
{
	int		ch;

	refresh();
	write_in_arena(mem, env);
	write_in_legend(env);
	mvwhline(env->legend, 61, 1, ' ', 58);
	wrefresh(env->legend);
	ch = 0;
	while (ch != 32)
		getch();
	destroy_win(env->legend);
	destroy_win(env->arena);
	endwin();
}
