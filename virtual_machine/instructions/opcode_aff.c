/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_sti_ldi_fork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:44:46 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 10:50:04 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	opcode_aff(t_list *proc_list, t_env *env)
{
	unsigned char	val;
	int				x;
	int				y;
	t_process		*process;

	process = (t_process*)proc_list->content;
	val = process->reg[process->par[0]] % 256;
	if (env->graph == -1)
		ft_printf("PLAYER %d --> {mag}%C{eoc}\n", process->process_number, val);
	else
	{
		attron(COLOR_PAIR(process->col));
		addch(val);
		addch(' ');
		attroff(COLOR_PAIR(process->col));
	}
	getyx(stdscr, y, x);
	if (x > 150)
	{
		x = 5;
		y++;
	}
}
