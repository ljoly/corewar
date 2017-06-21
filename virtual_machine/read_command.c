/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:45:29 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 11:04:49 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			get_ocp(t_list *proc_list, t_mem *mem)
{
	t_process	*proc;

	proc = (t_process*)proc_list->content;
	if (mem[proc->mem_index].ch == 0x0f || mem[proc->mem_index].ch == 0x01
			|| mem[proc->mem_index].ch == 0x0c || mem[proc->mem_index].ch == 9)
	{
		proc->ocp[1] = 0;
		proc->ocp[2] = 0;
		proc->ocp[0] = (mem[proc->mem_index].ch == 0x01) ? D4 : D2;
		return ;
	}
	proc->mem_index = (proc->mem_index + 1) % MEM_SIZE;
	proc->ocp[0] = ((mem[proc->mem_index].ch & 0b11000000) >> 6);
	proc->ocp[1] = ((mem[proc->mem_index].ch & 0b00110000) >> 4);
	proc->ocp[2] = ((mem[proc->mem_index].ch & 0b00001100) >> 2);
	if (proc->action == 1 || proc->action == 2 || (proc->action >= 6
				&& proc->action <= 8) || proc->action == 13)
	{
		proc->ocp[0] = (proc->ocp[0] == D2) ? D4 : proc->ocp[0];
		proc->ocp[1] = (proc->ocp[1] == D2) ? D4 : proc->ocp[1];
		proc->ocp[2] = (proc->ocp[2] == D2) ? D4 : proc->ocp[2];
	}
}

int				check_ocp(t_list *proc_list, t_mem *mem)
{
	unsigned char	hex;
	t_process		*proc;

	proc = (t_process*)proc_list->content;
	hex = mem[proc->mem_index].ch;
	if ((proc->action == 0x10 && hex != 0x40) || ((proc->action == 2
					|| proc->action == 0x0D) && hex != 0x90 && hex != 0xd0))
		return (0);
	if ((proc->action == 3 && hex != 0x60 && hex != 0x70)
			|| ((proc->action == 4 || proc->action == 5) && hex != 84))
		return (0);
	if ((proc->action >= 6 && proc->action <= 8) && hex != 84 && hex != 116
			&& hex != 100 && hex != 212 && hex != 244 && hex != 228
			&& hex != 148 && hex != 180 && hex != 164)
		return (0);
	if ((proc->action == 0x0A || proc->action == 0x0E)
			&& hex != 84 && hex != 100 && hex != 212 && hex != 228
			&& hex != 148 && hex != 164)
		return (0);
	if (proc->action == 0x0b && hex != 88 && hex != 84 && hex != 104
			&& hex != 100 && hex != 120 && hex != 116)
		return (0);
	return (1);
}

static void		assign_timer(int *cycles, unsigned char u)
{
	if (u == 0x10)
		*cycles = 1;
	if (u == 0x03 || u == 0x02)
		*cycles = 4;
	if (u == 0x06 || u == 0x07 || u == 0x08)
		*cycles = 5;
	if (u == 0x0d || u == 0x04 || u == 0x05 || u == 0x01)
		*cycles = 9;
	if (u == 0x09)
		*cycles = 19;
	if (u == 0x0a || u == 0x0B)
		*cycles = 24;
	if (u == 0x0e)
		*cycles = 49;
	if (u == 0x0c)
		*cycles = 799;
	if (u == 0x0f)
		*cycles = 999;
}

int				assign_jump(t_list *proc_list)
{
	int				count;
	unsigned char	act;
	t_process		*process;

	process = (t_process*)proc_list->content;
	act = ((t_process*)proc_list->content)->action;
	count = 0;
	if (act == 0x0f || act == 0x01 || act == 0x0c || act == 0x09)
		count = 1;
	else
		count = 2;
	count += (process->ocp[0] == 3) ? 2 : process->ocp[0];
	count += (process->ocp[1] == 3) ? 2 : process->ocp[1];
	count += (process->ocp[2] == 3) ? 2 : process->ocp[2];
	return (count);
}

void			read_command(t_mem *mem, t_list *proc_list)
{
	t_process	*process;

	process = (t_process*)proc_list->content;
	process->action = mem[process->mem_index].ch;
	assign_timer(&(process->cycle_timer), mem[process->mem_index].ch);
}
