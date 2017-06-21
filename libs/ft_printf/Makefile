# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 20:43:58 by bdal-can          #+#    #+#              #
#    Updated: 2017/06/18 20:50:43 by bdal-can         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra
INC = -I ./

SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = ../libft/

SRCS_NAME = ft_printf.c \
			ft_print_format.c \
			ft_checkandmark.c \
			ft_init_info.c \
			ft_get_info.c \
			ft_read_types_1.c \
			ft_read_types_2.c \
			ft_read_types_3.c \
			ft_read_types_4.c \
			ft_display.c \
			ft_display_2.c \
			ft_check_functions.c \
			ft_colours_and_other.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\n=> \x1B[32mLibftprintf.a Ready !\x1B[37m\n"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@printf "\e[38;5;208m▒\e[0m"
	@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
	@printf "=> \x1B[31mDeleting libftprintf .obj files...\x1B[37m\n"
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@printf "=> \x1B[31mDeleting libftprintf ...\x1B[37m\n"
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -rf $(NAME)

re: fclean all


.PHONY: all, clean, fclean, re
