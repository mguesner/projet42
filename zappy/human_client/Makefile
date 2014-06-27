#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/29 16:39:10 by mdarty            #+#    #+#              #
#    Updated: 2014/05/24 11:21:30 by mdarty           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS =		mlx_human.c\
			human_client.c\
			parse_option_client_human.c\
			connect_server_human.c\
			action_human.c\
			data_player_human.c\
			ft_memdel.c\
			read_human.c\
			read_check_line.c\
			info_server.c\
			ft_strsub.c\
			ft_splitspace.c\
			ft_delfulltab.c\
			ft_strsplit.c\
			ft_memdeltab.c\
			ft_tablen.c\
			ft_strdup.c\
			change_view_human.c\
			change_view_tool_human.c\
			change_case_humanc.c\
			ft_strnew.c\
			ft_itoa.c\
			init_img.c\
			init_img_view_me.c\
			init_img_fog_me.c\
			put_img_human.c\
			init_img_obj.c\
			init_button.c\
			print_img_my_player_view_human.c\
			print_img_my_player_void_human.c\
			print_img_my_player_fog_human.c\
			change_camera.c\
			init_img_void_me.c\
			init_img_player.c\
			tools.c\
			print_img_players.c\
			print_img_cmd.c\
			action_avance.c\
			action_droite.c\
			action_gauche.c\
			action_voir.c\
			action_voir_case.c\
			action_fork.c\
			action_prendre.c\
			action_poser.c\
			action_incant.c\
			mlx_button.c\
			init_img_inv.c\
			action_inventaire.c\
			print_img_inv.c\
			ft_strtrim.c\

CFLAGS =	-Wall -Werror -Wextra -g -I .

CC =		cc $(CFLAGS)

OBJ =		$(SRCS:.c=.o)

LIB =		libft/libft.a

NAME =		human_client

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -L/usr/X11/lib -lmlx -lXext -lX11;

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
