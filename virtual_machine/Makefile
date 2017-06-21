# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberlo <aberlo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/14 14:25:06 by aberlo            #+#    #+#              #
#    Updated: 2017/06/18 22:27:37 by bdal-can         ###   ########.fr        #
#    Updated: 2017/06/15 07:46:05 by aberlo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	corewar

SRC_1		=	cycle_to_die.c			\
				free.c					\
				main.c					\
				read_command.c  		\
				read_players_extra.c	\
				exec_commands.c			\
				read_players.c 			\
				
SRC_2		=	arg_parser.c	\
				state_b.c		\
				state_d.c		\
				state_machine.c	\
				state_a.c 		\
				state_c.c 		\
				state_e.c 		\

SRC_3		=	opcode_addsub.c		\
				opcode_andor.c		\
				opcode_ld.c 		\
				opcode_live.c   	\
				opcode_sti.c		\
				opcode_aff.c		\
				opcode_fork.c		\
				opcode_ldi.c 		\
				opcode_st.c			\
				opcode_zjmp.c		\
				
SRC_4		=	initialise_ncurses.c	\
				manage_windows.c		\
				write_content.c			\

INC		=	./vm.h

OBJ_1		=	$(addprefix $(OBJ_1_PATH),$(SRC_1:.c=.o))
OBJ_2		=	$(addprefix $(OBJ_2_PATH),$(SRC_2:.c=.o))
OBJ_3		=	$(addprefix $(OBJ_3_PATH),$(SRC_3:.c=.o))
OBJ_4		=	$(addprefix $(OBJ_4_PATH),$(SRC_4:.c=.o))

CC		=	gcc -g
FLAGS	=	-Wall -Wextra -Werror


LIBFTPRINTF	=	../libs/ft_printf/libftprintf.a
LIBFT 		=	../libs/libft/libft.a
LIBINC	=	-I../libs/ft_printf
LIBLINK	=	-L../libs/ft_printf -lftprintf

SRC_1_PATH	=	./
SRC_2_PATH	=	./parse_arguments/
SRC_3_PATH	=	./instructions/
SRC_4_PATH	=	./ncurses/
INC_PATH	=	./
OBJ_1_PATH	=	./obj/
OBJ_2_PATH	=	./obj/
OBJ_3_PATH	=	./obj/
OBJ_4_PATH	=	./obj/

all:	$(NAME)

$(NAME)	:	obj libftprintf $(OBJ_1) $(OBJ_2) $(OBJ_3) $(OBJ_4)
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ_1) $(OBJ_2) $(OBJ_3) $(OBJ_4) -lncurses
	@printf "\n=> \x1B[33mCompiling corewar...\x1b[37m"
	@printf "\n=> \x1B[32mExecutable corewar ready !\x1B[37m\n"

obj:
	@mkdir -p $(OBJ_1_PATH)
	@printf "=> \e[38;5;208mMaking corewar /obj dir... \x1B[37m"

libftprintf: $(LIBFTPRINTF)

$(LIBFTPRINTF):
	@make -C ../libs/ft_printf

$(OBJ_1_PATH)%.o: $(SRC_1_PATH)%.c $(INC)
	@$(CC) $(FLAGS) $(LIBINC) $(MLXINC) -I $(INC_PATH) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

$(OBJ_2_PATH)%.o: $(SRC_2_PATH)%.c $(INC)
	@$(CC) $(FLAGS) $(LIBINC) $(MLXINC) -I $(INC_PATH) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

$(OBJ_3_PATH)%.o: $(SRC_3_PATH)%.c $(INC)
	@$(CC) $(FLAGS) $(LIBINC) $(MLXINC) -I $(INC_PATH) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

$(OBJ_4_PATH)%.o: $(SRC_4_PATH)%.c $(INC)
	@$(CC) $(FLAGS) $(LIBINC) $(MLXINC) -I $(INC_PATH) -o $@ -c $<
	@printf "\e[38;5;208m▒\e[0m"

clean:
	@rm -rf $(OBJ_1_PATH)
	@printf "=> \x1B[31mDeleting corewar .obj files...\x1B[37m\n"
	@make -C ../libs/ft_printf clean

fclean:	clean
	@printf "=> \x1B[31mDeleting executable corewar...\x1B[37m\n"
	@rm -rf $(NAME)
	@make -C ../libs/ft_printf fclean

re: fclean all

norme:
	@norminette $(SRC_PATH)
	@norminette $(INC_PATH)

.PHONY: $(NAME) all clean fclean re
