# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/16 15:13:09 by bdal-can          #+#    #+#              #
#    Updated: 2017/06/18 20:53:02 by bdal-can         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
NAME2 = corewar

ASM_PATH = assembler/
VM_PATH = virtual_machine/

all:
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Make Libs ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C libs/ft_printf/
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Make Assembler ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(ASM_PATH)
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Make Virtual Machine ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(VM_PATH)
	@cp $(ASM_PATH)/$(NAME) .
	@cp $(VM_PATH)/$(NAME2) .

clean:
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Clean Assembler ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(ASM_PATH) clean
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Clean Virtual Machine ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(VM_PATH) clean

fclean:
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Fclean Assembler ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(ASM_PATH) fclean
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Fclean Virtual Machine ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(VM_PATH) fclean
	@rm -f $(NAME)
	@rm -f $(NAME2)

re: fclean all

.PHONY: re fclean clean all
