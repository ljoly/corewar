/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:46:22 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 22:39:54 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		ft_checkforerrors(unsigned char *buf, char *name, t_env *env,
		char *nkname)
{
	int		c;
	int		n;

	n = COREWAR_EXEC_MAGIC;
	c = -1;
	while (++c < 2192)
	{
		if ((c == 0 && buf[c] != n >> 24)
				|| (c == 1 && buf[c] != ((n >> 16) & 255)))
			err_free("Invalid file", name, env);
		if ((c == 2 && buf[c] != ((n >> 8) & 255))
				|| (c == 3 && buf[c] != (n & 255)))
			err_free("Invalid file", name, env);
		if (((c >= 4 && c < 132) || (c >= 140 && c < 2188))
				&& buf[c] > 127)
			err_free("Invalid name or comment", name, env);
		if (((c >= 132 && c < 136) || (c >= 2188 && c < 2192))
				&& buf[c] != 0)
			err_free("Invalid padding", name, env);
	}
	if (ft_strcmp(nkname, "") == 0)
		err_free("Empty player name", name, env);
}

static t_mem	*ft_readfile(int fd, t_mem *mem, t_list *play_list, t_env *env)
{
	int				ret;
	unsigned char	buf[2192];
	t_player		*pl;
	int				c;

	c = -1;
	pl = (t_player*)play_list->content;
	ret = 1;
	while (ret == 1 && ++c < 2192)
		ret = read(fd, &(buf[c]), 1);
	buf[c] = 0;
	((c = -1) > 0 || ret != 1) ? err_free("Invalid file", pl->name, env) : 0;
	pl->nkname = ft_strsub((char*)buf, 4, 128);
	ft_checkforerrors(buf, pl->name, env, pl->nkname);
	pl->motto = ft_strsub((char*)buf, 140, 2048);
	if ((pl->size = ft_bytestoint(buf + 136, 4)) > CHAMP_MAX_SIZE)
		err_free("Chammpion size is too large", pl->name, env);
	while (ret == 1 && ++c < pl->size)
	{
		ret = read(fd, &(mem[pl->i + c].ch), 1);
		mem[pl->i + c].col = pl->colour;
	}
	if (c != pl->size || pl->size < 1 || read(fd, &(mem[pl->i + c].ch), 1) == 1)
		err_free("Champion size error", pl->name, env);
	return (mem);
}

/*
** read the file until the beginning of the program.
** I need to check that the size stated at i 136
** corresponds to the correct size of the program.
**
**                         i        SIZE
** i of Magic N:        0        (4 bytes)
** i of Prog_name:      4        (128 bytes)
**                                   (4 bytes padding)
** i of Prog_size:      136      (4 bytes)
** i of Comment:        140      (2048 bytes)
**                                   (4 bytes padding)
** i of program:        2192
*/

static void		ft_assign_i(t_list *list, int dist, t_mem *mem)
{
	int		i;

	i = 0;
	while (list)
	{
		((t_player*)list->content)->i = i;
		mem[i].pc = TRUE;
		i += dist;
		list = list->next;
	}
}

static t_list	*init_pl(t_list *proc_list, t_list *play_list)
{
	t_process	process;
	t_list		*new;
	int			i;

	process.process_number = ((t_player*)play_list->content)->number;
	process.living = 0;
	process.pc = ((t_player*)play_list->content)->i;
	process.mem_index = ((t_player*)play_list->content)->i;
	process.cycle_timer = 0;
	process.action = 0;
	process.carry = 0;
	process.jump = 0;
	process.dead = FALSE;
	process.col = ((t_player*)play_list->content)->colour;
	i = -1;
	while (++i < 3)
		process.par[i] = 0;
	process.reg[0] = ((t_player*)play_list->content)->number;
	i = 0;
	while (++i < REG_NUMBER)
		process.reg[i] = 0;
	new = ft_lstnew((void*)&(process), sizeof(t_process));
	proc_list = (proc_list == NULL) ? new : proc_list;
	(proc_list != NULL) ? ft_lstaddinorder(&proc_list, new) : 0;
	return (proc_list);
}

void			read_players(t_env *env, t_mem *mem, t_list **pr_lst, int i)
{
	t_list		*play_list;
	int			fd;

	while (++i < MEM_SIZE && (mem[i].ch = 0) == 0)
	{
		mem[i].col = 70;
		mem[i].pc = FALSE;
		mem[i].hi = FALSE;
		mem[i].li = FALSE;
	}
	i = -1;
	play_list = env->players_list;
	ft_assign_i(play_list, MEM_SIZE / env->n_players, mem);
	while (++i < env->n_players)
	{
		fd = open(((t_player*)play_list->content)->name, O_RDONLY);
		mem = ft_readfile(fd, mem, play_list, env);
		close(fd);
		play_list = play_list->next;
	}
	i = -1;
	play_list = env->players_list;
	while (++i < env->n_players && (*pr_lst = init_pl(*pr_lst, play_list)))
		play_list = play_list->next;
	(env->graph == -1) ? print_introduction(env->players_list) : 0;
}
