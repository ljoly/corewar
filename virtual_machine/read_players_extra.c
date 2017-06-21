/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_players_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 18:22:01 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 20:16:59 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_introduction(t_list *play_list)
{
	t_player	*player;

	ft_printf("{cyan}\nIntroducing contestants...{eoc}\n");
	while (play_list)
	{
		player = (t_player*)play_list->content;
		ft_printf("* {green}Player %d{eoc}, ", player->number);
		ft_printf("weighing %d bytes, ", player->size);
		ft_printf("goes by the name of '{yel}%s{eoc}'. ", player->nkname);
		ft_printf("His motto is '%s'\n", player->motto);
		play_list = play_list->next;
	}
}

void	ft_lstaddinorder(t_list **list, t_list *new)
{
	t_list	*proc_list;
	t_list	*tmp;

	proc_list = *list;
	if (!list || !new)
		return ;
	if (((t_process*)new->content)->process_number >
			((t_process*)proc_list->content)->process_number)
		ft_lstadd(list, new);
	else
	{
		while (((t_process*)new->content)->process_number
				< ((t_process*)proc_list->content)->process_number
				&& proc_list->next)
			proc_list = proc_list->next;
		if (!(proc_list->next))
			ft_lstaddend(list, new);
		else
		{
			tmp = proc_list->next;
			proc_list->next = new;
			new->next = tmp;
		}
	}
}

void	err_free(char *str, char *name, t_env *env)
{
	ft_putstr_fd("\x1B[31mERROR\x1B[0m\n", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" --- ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	free_env(env);
	exit(0);
}

void	add_color_and_highlight(t_mem *mem, int index, int col)
{
	mem[index].hi = 49;
	mem[index].col = col;
	mem[(index + 1) % MEM_SIZE].hi = 49;
	mem[(index + 1) % MEM_SIZE].col = col;
	mem[(index + 2) % MEM_SIZE].hi = 49;
	mem[(index + 2) % MEM_SIZE].col = col;
	mem[(index + 3) % MEM_SIZE].hi = 49;
	mem[(index + 3) % MEM_SIZE].col = col;
}
