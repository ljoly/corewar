/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:16:02 by ljoly             #+#    #+#             */
/*   Updated: 2017/06/16 20:20:13 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../../libs/libft/libft.h"
# include "../../libs/ft_printf/ft_printf.h"

/*
** Defining op_codes
*/
# define LIVE	1
# define LD		2
# define ST		3
# define ADD	4
# define SUB	5
# define AND	6
# define OR		7
# define XOR	8
# define ZJMP	9
# define LDI	10
# define STI	11
# define FORK	12
# define LLD	13
# define LLDI	14
# define LFORK	15
# define AFF	16

# define NBR_OP	16

# define START 0
# define USE 1
# define END 2

typedef struct s_op		t_op;
typedef struct s_label	t_label;

struct					s_op
{
	char				op_type;
	char				ocp;
	int					pos;
	int					args[MAX_ARGS_NUMBER];
	char				*label_args[MAX_ARGS_NUMBER];
	t_op				*next;
};

struct					s_label
{
	char				*name;
	int					pos;
	t_label				*next;
};

typedef struct			s_format
{
	t_op				**op;
	t_label				**label;
}						t_format;

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

typedef struct			s_binary
{
	t_header			header;
	t_format			format;
}						t_binary;

typedef struct			s_read
{
	char				*line;
	int					ret;
}						t_read;

/*
** Checking file format and getting environment using a finite-state machine
*/
void					file_parsing(int fd_s, char *asm_file_name);
int						state_machine(int action, char **str, t_binary *file);

/*
** Each state of the machine is defined by a function
*/
void					*state_initial(char **str, t_binary *file);
void					*state_a(char **str, t_binary *file);
void					*state_b(char **str, t_binary *file);
void					*state_c(char **str, t_binary *file);
void					*state_d(char **str, t_binary *file);
void					*state_e(char **str, t_binary *file);
void					*state_f(char **str, t_binary *file);
void					*state_g(char **str, t_binary *file);

/*
** Lexer
*/
t_boolean				lex_eol(char **str);
t_boolean				lex_blanks(char **str);
t_boolean				lex_str_name(char **str);
t_boolean				lex_str(char **str, char *prog_feature, int max_len);
t_boolean				lex_str_comm(char **str);
t_boolean				lex_op(char **str, t_binary *file);
t_boolean				lex_op_arg(char **str, t_binary *f, t_op *op, int arg);
t_boolean				lex_label(char **str, t_binary *file);
t_boolean				lex_label_name(char **str, char **name);
t_boolean				lex_label_arg(char **str, char **name);
t_boolean				lex_num(char **str, int *args, int reg);

void					ft_add_op(t_op **op, t_op *new);
void					ft_add_label(t_label **label, t_label *new);

/*
** Getting op_codes specs
*/
char					*get_op_name(int id);
int						get_op_length(int id);
int						get_nbr_arg(int id);
int						get_available_arg(int id, int arg_index);
int						get_arg_length(int o, int arg_type);

/*
** Making of the binary file
*/
t_boolean				replace_labels(t_binary *file);
void					write_binary(t_binary *file, int fd);
unsigned int			little_to_big_endian(unsigned int n);

/*
** Handling errors
*/
void					ft_err(int err_code);

#endif
