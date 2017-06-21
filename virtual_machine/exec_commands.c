/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 10:17:49 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 11:04:41 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		ft_jump(t_list *proc_list, t_mem *mem)
{
	int			i;
	t_process	*process;

	process = (t_process*)proc_list->content;
	mem[process->pc].pc = FALSE;
	process->mem_index = (process->pc + process->jump) % MEM_SIZE;
	process->pc = process->mem_index;
	mem[process->pc].pc = TRUE;
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

static int	store_parameters(t_list *proc_list, t_mem *mem)
{
	int			i;
	t_process	*proc;

	proc = (t_process*)proc_list->content;
	i = -1;
	while (++i < 3 && proc->ocp[i] != 0)
	{
		if (proc->ocp[i] == RG)
		{
			if (mem[proc->mem_index].ch > 16 || mem[proc->mem_index].ch < 1)
				return (0);
			proc->par[i] = mem[proc->mem_index].ch - 1;
		}
		else if (proc->ocp[i] == IND || proc->ocp[i] == D2)
			proc->par[i] = ft_bytestointover(T_DIR, proc->mem_index, mem);
		else if (proc->ocp[i] == D4)
			proc->par[i] = ft_bytestointover(4, proc->mem_index, mem);
		if (proc->ocp[i] == IND)
			proc->mem_index = (proc->mem_index + 2) % MEM_SIZE;
		else
			proc->mem_index = (proc->mem_index + proc->ocp[i]) % MEM_SIZE;
	}
	return (1);
}

static int	ft_action(t_mem *mem, t_list *proc_list, t_list **l_h, t_env *env)
{
	unsigned char	act;

	act = ((t_process*)proc_list->content)->action;
	if (act == 1)
		if (opcode_live(proc_list, l_h, env, mem) == 0)
			return (0);
	if (act == 2 || act == 13)
		opcode_ld(proc_list, mem);
	if (act == 3)
		opcode_st(proc_list, mem);
	if (act == 4 || act == 5)
		opcode_addsub(proc_list);
	if (act >= 6 && act <= 8)
		opcode_andor(proc_list, mem);
	if (act == 9)
		opcode_zjmp(proc_list, mem);
	if (act == 10 || act == 14)
		opcode_ldi(proc_list, mem);
	if (act == 11)
		opcode_sti(proc_list, mem);
	if (act == 12 || act == 15)
		opcode_fork(proc_list, l_h, mem);
	if (act == 16)
		opcode_aff(proc_list, env);
	return (1);
}

int			wrong_jump(t_process *process, unsigned char ocp)
{
	int		jump;

	jump = 2;
	if (process->action == 16)
		jump += (((ocp & 192) >> 6) == 3) ? 2 : ((ocp & 192) >> 6);
	if (process->action == 2 || process->action == 3 || process->action == 13)
	{
		jump += (((ocp & 192) >> 6) == 3) ? 2 : ((ocp & 192) >> 6);
		jump += (((ocp & 48) >> 4) == 3) ? 2 : ((ocp & 48) >> 4);
	}
	else
	{
		jump += (((ocp & 192) >> 6) == 3) ? 2 : ((ocp & 192) >> 6);
		jump += (((ocp & 48) >> 4) == 3) ? 2 : ((ocp & 48) >> 4);
		jump += (((ocp & 12) >> 2) == 3) ? 2 : ((ocp & 12) >> 2);
	}
	return (jump);
}

void		command_exec(t_mem *mem, t_list *pr_lst, t_list **lst_h, t_env *env)
{
	t_process		*process;

	process = (t_process*)pr_lst->content;
	get_ocp(pr_lst, mem);
	if (check_ocp(pr_lst, mem) == 0)
	{
		process->jump = wrong_jump(process, mem[process->mem_index].ch);
		ft_jump(pr_lst, mem);
		return ;
	}
	process->jump = assign_jump(pr_lst);
	process->mem_index = (process->mem_index + 1) % MEM_SIZE;
	if (store_parameters(pr_lst, mem) == 0)
	{
		ft_jump(pr_lst, mem);
		return ;
	}
	if (ft_action(mem, pr_lst, lst_h, env) == 0)
	{
		ft_jump(pr_lst, mem);
		return ;
	}
	process->cycle_timer = 0;
	if (process->action != 0)
		ft_jump(pr_lst, mem);
}
