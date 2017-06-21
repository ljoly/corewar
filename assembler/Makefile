# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/16 20:28:02 by ljoly             #+#    #+#              #
#    Updated: 2017/06/18 20:43:46 by bdal-can         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
SRCS_ASM = asm.c parsing.c op_specs.c replace_labels.c write_binary.c big_endian.c
SRCS_LEX = lexer_blanks.c lexer_eol.c lexer_label.c lexer_label_arg.c \
		   lexer_label_name.c lexer_num.c lexer_op.c lexer_op_arg.c \
		   lexer_str.c lexer_str_comm.c lexer_str_name.c
SRCS_ST = state_machine.c state_initial.c state_a.c state_b.c state_c.c \
		  state_d.c state_e.c state_f.c state_g.c

ASM_PATH = ./srcs/
LEX_PATH = ./srcs/lexer/
ST_PATH = ./srcs/state_functions/

SRCS = $(addprefix $(ASM_PATH), $(SRCS_ASM)) \
	   $(addprefix $(LEX_PATH), $(SRCS_LEX)) \
	   $(addprefix $(ST_PATH), $(SRCS_ST)) \

OBJ = $(SRCS:.c=.o)
OBJ_PATH = ./obj

FLAGS = -Wall -Werror -Wextra
LIB = ../libs/ft_printf/
LIBFT = ../libs/libft/
HEADER = ./includes

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all: $(NAME)

$(NAME): void $(OBJ)
	@make -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIB) -lftprintf -L $(LIBFT) -lft
	@printf "\n=> \x1B[33mCompiling assembler...\x1b[37m"
	@printf "\n=> \x1B[32mExecutable asm ready !\x1B[37m\n"

void:
	@printf "=> \e[38;5;208mMaking assembler obj files... \x1B[37m"

%.o: %.c
	@gcc $(FLAGS) -I $(LIB) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

clean:
	@make -C $(LIB) clean
	@rm -rf $(OBJ)
	@printf "=> \x1B[31mDeleting assembler .obj files...\x1B[37m\n"

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
	@printf "=> \x1B[31mDeleting executable asm...\x1B[37m\n"

re: fclean all

.PHONY: all clean fclean re
