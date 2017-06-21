/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_sti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:33:17 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 21:53:41 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		action(t_process *pro, t_mem *mem, int *v1)
{
	while (pro->par[1] + MEM_SIZE < 0)
		pro->par[1] += MEM_SIZE;
	*v1 = ft_bytestointover(2, (MEM_SIZE + pro->pc +
				(pro->par[1] % IDX_MOD)) % MEM_SIZE, mem);
}

static void		action2(t_process *pro, t_mem *mem, int index)
{
	mem[index].ch = pro->reg[pro->par[0]] >> 24;
	mem[(index + 1) % MEM_SIZE].ch = (pro->reg[pro->par[0]] >> 16) & 0xff;
	mem[(index + 2) % MEM_SIZE].ch = (pro->reg[pro->par[0]] >> 8) & 0xff;
	mem[(index + 3) % MEM_SIZE].ch = pro->reg[pro->par[0]] & 0xff;
	add_color_and_highlight(mem, index % MEM_SIZE, pro->col);
}

void			opcode_sti(t_list *proc_list, t_mem *mem)
{
	int			res;
	int			v1;
	int			v2;
	int			index;
	t_process	*pro;

	pro = (t_process*)proc_list->content;
	pro->reg[pro->par[0]] = pro->reg[pro->par[0]];
	if (pro->ocp[1] == RG)
		v1 = pro->reg[pro->par[1]];
	else if (pro->ocp[1] == D2)
		v1 = pro->par[1];
	else
		action(pro, mem, &v1);
	if (pro->ocp[2] == D2)
		v2 = pro->par[2];
	else
		v2 = pro->reg[pro->par[2]];
	res = v1 + v2;
	while (res + MEM_SIZE < 0)
		res += MEM_SIZE;
	index = (MEM_SIZE + pro->pc + (res % IDX_MOD)) % MEM_SIZE;
	action2(pro, mem, index);
}
