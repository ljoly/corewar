/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intialise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:24:39 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 13:45:31 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		set_pairs(void)
{
	init_color(70, 400, 400, 400);
	init_color(11, 580, 1000, 1000);
	init_color(12, 1000, 1000, 570);
	init_color(13, 1000, 590, 1000);
	init_color(14, 590, 1000, 590);
	init_color(5, 1000, 0, 0);
	init_color(50, 310, 600, 220);
	init_pair(70, 70, COLOR_BLACK);
	init_pair(1, 1, COLOR_BLACK);
	init_pair(2, 2, COLOR_BLACK);
	init_pair(3, 3, COLOR_BLACK);
	init_pair(4, 4, COLOR_BLACK);
	init_pair(5, 5, COLOR_BLACK);
	init_pair(11, 11, COLOR_BLACK);
	init_pair(12, 12, COLOR_BLACK);
	init_pair(13, 13, COLOR_BLACK);
	init_pair(14, 14, COLOR_BLACK);
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(31, COLOR_BLACK, 11);
	init_pair(32, COLOR_BLACK, 12);
	init_pair(33, COLOR_BLACK, 13);
	init_pair(34, COLOR_BLACK, 14);
	init_pair(50, 50, COLOR_BLACK);
}

void			initialise_ncurses(t_env *env, t_mem *mem)
{
	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	noecho();
	start_color();
	set_pairs();
	curs_set(0);
	env->arena = create_newwin(66, 195, 0, 0);
	env->legend = create_newwin(66, 60, 0, 195);
	env->sleep = (env->one_by_one == TRUE) ? 0 : 100000;
	refresh();
	wrefresh(env->legend);
	wrefresh(env->arena);
	move(66, 5);
	graphic(env, mem);
	key_step();
}

void			key_step(void)
{
	int		ch;

	ch = 0;
	while (ch != 115)
		ch = getch();
}

void			graphic(t_env *env, t_mem *mem)
{
	usleep(env->sleep);
	if (getch() == 258 && env->sleep < 60000)
		env->sleep += 50000;
	if (getch() == 259 && env->sleep > -1)
		env->sleep -= 50000;
	write_in_arena(mem, env);
	write_in_legend(env);
	if (env->one_by_one)
		key_step();
	refresh();
}
