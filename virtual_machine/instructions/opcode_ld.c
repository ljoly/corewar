/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_ld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:30:44 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 21:52:00 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	opcode_ld(t_list *proc_list, t_mem *mem)
{
	int			val;
	int			index;
	t_process	*pro;

	pro = (t_process*)proc_list->content;
	if (pro->ocp[0] == D4)
		val = pro->par[0];
	else
	{
		while (pro->par[0] < 0 && pro->par[0] + MEM_SIZE < 0)
			pro->par[0] += MEM_SIZE;
		if (pro->action == 2)
		{
			index = (MEM_SIZE + pro->pc + (pro->par[0] % IDX_MOD)) % MEM_SIZE;
			val = ft_bytestointover(4, index, mem);
		}
		else
		{
			index = (MEM_SIZE + pro->pc + pro->par[0]) % MEM_SIZE;
			val = ft_bytestointover(2, index, mem);
		}
	}
	pro->reg[pro->par[1]] = val;
	pro->carry = (val == 0) ? 1 : 0;
}
