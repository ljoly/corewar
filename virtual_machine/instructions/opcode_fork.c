/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_forl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:34:34 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 21:54:32 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	initialise_fork(t_list *list)
{
	int			i;
	t_process	*new_proc;

	new_proc = (t_process*)list->content;
	i = -1;
	new_proc->living = 0;
	new_proc->cycle_timer = 0;
	new_proc->jump = 0;
	new_proc->dead = FALSE;
	new_proc->action = 0;
	while (++i < 3)
	{
		new_proc->ocp[i] = 0;
		new_proc->par[i] = 0;
	}
}

void	opcode_fork(t_list *proc_list, t_list **list_head, t_mem *mem)
{
	int			i;
	t_process	new_proc;
	t_list		*new;
	t_process	*process;

	process = (t_process*)proc_list->content;
	i = process->par[0];
	while (i < 0 && i + MEM_SIZE < 0)
		i += MEM_SIZE;
	if (process->action == 12)
		new_proc.pc = (MEM_SIZE + process->pc + (i % IDX_MOD)) % MEM_SIZE;
	else
		new_proc.pc = (MEM_SIZE + process->pc + i) % MEM_SIZE;
	new_proc.process_number = process->process_number;
	i = -1;
	while (++i < REG_NUMBER)
		new_proc.reg[i] = process->reg[i];
	new_proc.mem_index = new_proc.pc;
	mem[new_proc.pc].pc = TRUE;
	new_proc.col = process->col;
	new_proc.carry = process->carry;
	new = ft_lstnew(((void*)&new_proc), sizeof(t_process));
	initialise_fork(new);
	ft_lstadd(list_head, new);
}
