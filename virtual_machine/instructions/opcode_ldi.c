/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_ldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:33:38 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/16 10:59:37 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

static void		action(t_process *pro, t_mem *mem, int *v1)
{
	while (pro->par[0] < 0 && pro->par[0] + MEM_SIZE < 0)
		pro->par[0] += MEM_SIZE;
	if (pro->ocp[0] == IND && pro->action == 10)
		*v1 = ft_bytestointover(4, (MEM_SIZE + pro->pc + (pro->par[0]
						% IDX_MOD)) % MEM_SIZE, mem);
	else
		*v1 = ft_bytestointover(4, (MEM_SIZE + pro->pc + pro->par[0])
				% MEM_SIZE, mem);
}

void			opcode_ldi(t_list *proc_list, t_mem *mem)
{
	int			v1;
	int			v2;
	int			index;
	t_process	*pro;
	int			res;

	pro = (t_process*)proc_list->content;
	if (pro->ocp[0] == RG)
		v1 = pro->reg[pro->par[0]];
	else if (pro->ocp[0] == D2)
		v1 = pro->par[0];
	else
		action(pro, mem, &v1);
	v2 = (pro->ocp[1] == RG) ? pro->reg[pro->par[1]] : pro->par[1];
	res = v1 + v2;
	while (res + MEM_SIZE < 0)
		res += MEM_SIZE;
	if (pro->action == 10)
		index = (MEM_SIZE + pro->pc + (res % IDX_MOD)) % MEM_SIZE;
	else
		index = (MEM_SIZE + pro->pc + (res)) % MEM_SIZE;
	pro->reg[pro->par[2]] = ft_bytestointover(4, index, mem);
	pro->carry = (pro->reg[pro->par[2]] == 0) ? 1 : 0;
}
