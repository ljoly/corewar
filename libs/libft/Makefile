# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdal-can <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 19:16:24 by bdal-can          #+#    #+#              #
#*   Updated: 2017/05/30 20:25:26 by tlavenan    ##    ##     ##   ######.fr  *#
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_isspace.c \
	  ft_lstaddend.c \
	  ft_printtab_char.c \
	  ft_printtab_int.c \
	  ft_createtab_int.c \
	  ft_printtab.c \
	  ft_sqrt.c \
	  ft_createtab_char.c \
	  ft_strnjoin.c \
	  ft_strjoinfree.c \
	  ft_strndup.c \
	  ft_capitalise.c \
	  ft_itoa_base.c \
	  ft_putwchar.c \
	  ft_putwstr.c \
	  ft_putnwstr.c \
	  ft_wcsdup.c \
	  ft_wcsndup.c \
	  ft_wcslen.c \
	  ft_wcsbytelen.c \
	  ft_ishex.c \
	  ft_strjoinfree1st.c \
	  ft_atoi_base.c \
	  ft_pos_power.c \
	  ft_nbrswap.c \
	  ft_wcountbyte.c \
	  ft_printtab_fd.c \
	  get_next_line.c \
	  ft_strmerge.c \
	  ft_count_words.c \
	  ft_isalldigits.c \
	  ft_free_tab.c \
	  ft_free3strings.c \
	  ft_freeinsidelst.c \
	  ft_lstcountelem.c \
      ft_clist_addfirst.c \
	  ft_clist_addlast.c \
	  ft_clist_create.c \
	  ft_clist_first.c \
	  ft_clist_last.c \
	  ft_clist_rmfirst.c \
	  ft_clist_destroy.c \
	  ft_isinarray.c \
	  ft_lstfree.c \
	  ft_check_argc.c \
	  ft_open_file.c \
	  ft_bytestoint.c \
	  ft_cmparr.c\
	  ft_savearg.c\
	  ft_error.c \
	  ft_array_have_doubles.c

OBJ=$(SRC:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n=> \x1B[33mCompiling Libft...\x1b[37m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\n=> \x1B[32mLibft.a Ready !\x1B[37m"

%.o : %.c
	@printf "\e[38;5;208m▒\e[0m"
	@gcc -o $@ -c $(FLAGS) $^

clean:
	@rm -f $(OBJ)
	@printf "=> \x1B[31mDeleting libft .obj files...\x1B[37m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "=> \x1B[31mDeleting libft.a.. \x1B[37m\n"

re: fclean all
