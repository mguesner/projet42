# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/29 13:34:52 by mguesner          #+#    #+#              #
#    Updated: 2014/05/31 17:11:51 by mguesner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemipc

NAME2 = vlemipc

OBJ = main.o \
	  ft_lemipc.o \
	  ft_initplay.o \
	  ft_play.o \
	  ft_alone.o \
	  ft_death.o \
	  ft_move.o\
	  ft_lock.o \
	  ft_unlock.o \
	  ft_isnum.o \
	  ft_perror.o \
	  ft_putmap.o

OBJ2 = vmain.o \
	   ft_perror.o \
	   ft_init.o\
	   ft_refresh.o \
	   ft_legend.o

CC = gcc -g -Wall -Wextra -Werror -I $(LIB)

LIB = libft

all: lib $(NAME) $(NAME2)

lib:
	make -C $(LIB)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L $(LIB) -lft

$(NAME2): $(OBJ2)
	$(CC) -o $(NAME2) $(OBJ2) -L $(LIB) -lft -lncurses

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

libfclean:
	make -C $(LIB) fclean

libre:
	make -C $(LIB) re

re: libre fclean all

.PHONY: clean all re fclean
