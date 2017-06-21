/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_ld_st_addsub_andor_zjmp.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:37:03 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/15 10:01:31 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	opcode_zjmp(t_list *proc_list, t_mem *mem)
{
	int			index;
	int			i;
	t_process	*process;

	process = (t_process*)proc_list->content;
	index = process->par[0] % IDX_MOD;
	while (index + MEM_SIZE < 0)
		index += MEM_SIZE;
	if (process->carry == 1)
	{
		mem[process->pc].pc = FALSE;
		process->pc = (MEM_SIZE + process->pc + index) % MEM_SIZE;
		mem[process->pc].pc = TRUE;
		process->mem_index = process->pc;
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
}
