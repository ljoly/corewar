/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_andor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:32:05 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 10:57:46 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		action(t_process *pro, int *v1, int *v2)
{
	if (pro->action == 6)
		pro->reg[pro->par[2]] = *v1 & *v2;
	else if (pro->action == 7)
		pro->reg[pro->par[2]] = *v1 | *v2;
	else if (pro->action == 8)
		pro->reg[pro->par[2]] = *v1 ^ *v2;
}

static void		action2(t_process *pro, t_mem *mem, int *v2)
{
	while (pro->par[1] < 0 && pro->par[1] + MEM_SIZE < 0)
		pro->par[1] += MEM_SIZE;
	*v2 = ft_bytestointover(4, (MEM_SIZE + pro->pc
				+ (pro->par[1] % IDX_MOD)) % MEM_SIZE, mem);
}

void			opcode_andor(t_list *proc_list, t_mem *mem)
{
	int			v1;
	int			v2;
	t_process	*pro;

	pro = (t_process*)proc_list->content;
	v1 = (pro->ocp[0] == RG) ? pro->reg[pro->par[0]] : pro->par[0];
	if (pro->ocp[0] == IND)
	{
		while (pro->par[0] < 0 && pro->par[0] + MEM_SIZE < 0)
			pro->par[0] += MEM_SIZE;
		v1 = ft_bytestointover(4, (MEM_SIZE + pro->pc
					+ (pro->par[0] % IDX_MOD)) % MEM_SIZE, mem);
	}
	if (pro->ocp[1] == RG)
		v2 = pro->reg[pro->par[1]];
	else if (pro->ocp[1] == D4)
		v2 = pro->par[1];
	else if (pro->ocp[1] == IND)
		action2(pro, mem, &v2);
	action(pro, &v1, &v2);
	pro->carry = (pro->reg[pro->par[2]] == 0) ? 1 : 0;
}
