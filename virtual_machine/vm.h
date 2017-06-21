/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 11:26:59 by bdal-can          #+#    #+#             */
/*   Updated: 2017/06/18 22:19:30 by bdal-can         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "parse_arguments/arg_parser.h"
# include "./op.h"
# include <ncurses.h>

# define U1 "Unfortunately there is no winner. "
# define U2 "All champions died with honour on the battlefield."
# define U3 "This message was written with the blood they shed."
# define U4 "Please pray for their souls."
# define LIV "Lives in current period"
# define W1 "Please bow to his majesty the champion "
# define W2 " of Scotland, first of his name, also known as Player "
# define T1 "The game ended but some players are still alive. The "
# define T2 T1"last player to declare himself as alive was "
# define T3 " (player "
# define T4 "The game ended but some players are still alive."
# define T5 "The last player to signal himself as alive is"

# define RG 1
# define D2 2
# define D4 4
# define IND 3

typedef struct		s_mem
{
	unsigned char	ch;
	short int		col;
	t_boolean		pc;
	int				hi;
	int				li;
}					t_mem;

typedef struct		s_process
{
	int				process_number;
	int				living;
	int				reg[REG_NUMBER];
	int				pc;
	int				mem_index;
	int				cycle_timer;
	int				action;
	int				ocp[3];
	int				carry;
	int				par[3];
	int				jump;
	short int		col;
	t_boolean		dead;

}					t_process;

typedef struct		s_env
{
	int				f_dump;
	int				graph;
	t_boolean		one_by_one;
	int				n_players;
	t_list			*players_list;
	int				tmp;
	int				alive;
	WINDOW			*arena;
	WINDOW			*legend;
	int				cycles;
	int				cc;
	int				ctd;
	int				sleep;
	t_boolean		gameover;
	int				live_play;
}					t_env;

typedef struct		s_player
{
	char			*name;
	int				number;
	char			*motto;
	char			*nkname;
	int				i;
	int				size;
	int				live;
	int				live_addr;
	short int		colour;
	int				dead;
}					t_player;
/*
** main.c
*/
void				ft_advance(t_list *proc_list, t_mem *mem);

/*
** read_players.c
*/
void				read_players(t_env *env, t_mem *mem, t_list **p_l, int i);

/*
** read_players_extra.c
*/
void				err_free(char *str, char *name, t_env *env);
void				ft_lstaddinorder(t_list **list, t_list *new);
void				print_introduction(t_list *play_list);
void				add_color_and_highlight(t_mem *mem, int index, int col);

/*
** read_command.c
*/
int					check_ocp(t_list *proc_list, t_mem *mem);
void				read_command(t_mem *mem, t_list *proc_list);
int					assign_jump(t_list *proc_list);
void				get_ocp(t_list *proc_list, t_mem *mem);

/*
** exec_commands.c
*/
void				ft_jump(t_list *proc_list, t_mem *mem);
void				command_exec(t_mem *m, t_list *p_l, t_list **l_h, t_env *e);

/*
** cycle_to_die.c
*/
int					ft_bytestointover(int size, int index, t_mem *mem);
t_list				*kill_proc(t_list **l_h, t_list *tmp, t_env *env, t_mem *m);
void				change_ctd(int lives, int *ctd, t_env *env);
void				reset_lives_and_mark_dead(t_env *env, t_list *p_l, int l);

/*
** free.c
*/
int					count_lives(t_list *proc_list);
void				gameover(t_env *env, char *name, int col);
void				free_env(t_env *env);
void				free_proc_list(t_list *proc_list);
int					fdump(t_mem *mem, t_env *env, t_list *proc_list);

/*
** instructions
*/
int					opcode_live(t_list *p_l, t_list **l_h, t_env *e, t_mem *m);
void				opcode_ld(t_list *proc_list, t_mem *mem);
void				opcode_st(t_list *proc_list, t_mem *mem);
void				opcode_addsub(t_list *proc_list);
void				opcode_andor(t_list *proc_list, t_mem *mem);
void				opcode_zjmp(t_list *proc_list, t_mem *mem);
void				opcode_ldi(t_list *proc_list, t_mem *mem);
void				opcode_sti(t_list *proc_list, t_mem *mem);
void				opcode_fork(t_list *proc_list, t_list **l_h, t_mem *mem);
void				opcode_aff(t_list *proc_list, t_env *env);

/*
** ncurses/initialise_necurses.c
*/
void				initialise_ncurses(t_env *env, t_mem *mem);
void				key_step(void);

/*
** ncurses/write_content.c
*/
void				write_in_arena(t_mem *mem, t_env *env);
void				write_in_legend(t_env *env);

/*
** ncurses/manage_windows.c
*/
WINDOW				*create_newwin(int h, int w, int starty, int startx);
void				destroy_win(WINDOW *local_win);
void				graphic(t_env *env, t_mem *mem);
void				winner_message(t_env *env, char *name, int col);
void				end_graph(t_env *env, t_mem *mem);

#endif
