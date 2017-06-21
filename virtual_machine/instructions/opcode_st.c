/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_st.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:31:08 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 21:52:19 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	opcode_st(t_list *proc_list, t_mem *mem)
{
	int			val;
	int			index;
	t_process	*process;

	process = (t_process*)proc_list->content;
	val = process->reg[process->par[0]];
	if (process->ocp[1] == RG)
		process->reg[process->par[1]] = val;
	else if (process->ocp[1] == IND)
	{
		while (process->par[1] + MEM_SIZE < 0)
			process->par[1] += MEM_SIZE;
		index = (MEM_SIZE + process->pc + (process->par[1] % IDX_MOD))
			% MEM_SIZE;
		mem[index].ch = val >> 24;
		add_color_and_highlight(mem, index % MEM_SIZE, process->col);
		mem[(index + 1) % MEM_SIZE].ch = (val >> 16) & 0xff;
		mem[(index + 2) % MEM_SIZE].ch = (val >> 8) & 0xff;
		mem[(index + 3) % MEM_SIZE].ch = val & 0xff;
	}
}
