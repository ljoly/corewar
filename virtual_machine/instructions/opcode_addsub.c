/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode_addsub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 21:31:35 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/15 09:45:49 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	opcode_addsub(t_list *proc_list)
{
	int			v1;
	int			v2;
	t_process	*process;

	process = (t_process*)proc_list->content;
	v1 = process->reg[process->par[0]];
	v2 = process->reg[process->par[1]];
	if (process->action == 4)
		process->reg[process->par[2]] = v1 + v2;
	else if (process->action == 5)
		process->reg[process->par[2]] = v1 - v2;
	process->carry = (process->reg[process->par[2]] == 0) ? 1 : 0;
}
