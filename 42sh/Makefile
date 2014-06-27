# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/24 13:12:51 by mguesner          #+#    #+#              #
#    Updated: 2014/03/27 13:45:27 by mguesner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

OBJ = main.o \
	  creat_env.o \
	  ft_error.o \
	  ft_init.o \
	  ft_sh.o \
	  ft_putonterm.o \
	  ft_exit.o \
	  ft_del_char.o \
	  ft_add.o \
	  ft_realloc.o \
	  ft_print.o \
	  ft_init_e.o \
	  ft_prompt.o \
	  ft_getenv.o \
	  ft_enter.o \
	  ft_go.o \
	  ft_path.o \
	  ft_tabdel.o \
	  ft_parserbis.o \
	  ft_create_elem.o \
	  ft_parsecmd.o \
	  ft_parseend.o \
	  ft_parseerror.o \
	  ft_parseredir.o \
	  ft_createstr.o \
	  ft_isop.o \
	  is_builtin.o \
	  ft_lstdel.o \
	  ft_parseor.o \
	  ft_parseand.o \
	  ft_make_tree.o \
	  ft_new_node.o \
	  ft_see_tree.o \
	  ft_del_tree.o \
	  ft_exec.o \
	  ft_exec_pipe.o \
	  ft_fork.o \
	  ft_cmd.o \
	  ft_redir.o \
	  ft_tablen.o \
	  ft_file_error.o \
	  ft_builtin.o \
	  ft_cd.o \
	  ft_setenv.o \
	  ft_error_cd.o \
	  ft_isdir.o \
	  ft_env.o \
	  ft_exec_redirect.o \
	  ft_cpyenv.o \
	  ft_presetenv.o \
	  ft_add_env.o \
	  ft_unsetenv.o \
	  ft_supressslash.o \
	  ft_strsupressslash.o \
	  ft_arrow.o \
	  ft_signal.o \
	  ft_stock.o \
	  ft_reput_prompt.o \
	  ft_add_hystor.o \
	  ft_hystor.o \
	  ft_autocomplete.o \
	  ft_autocomplete2.o \
	  ft_autocomplete3.o \
	  ft_autocomplete4.o \
	  ft_tab.o \
	  ft_add_job.o \
	  ft_echo.o \
	  ft_aff.o \
	  ft_scroll.o \
	  ft_reset.o \
	  ft_affbis.o \
	  ft_envbis.o \
	  ft_leftson.o \
	  ft_make_treebis.o

CC = gcc -g -Wall -Wextra -Werror

LIB2 = -ltermcap

LIB = -L libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(LIB2) -I libft -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) -I libft -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
