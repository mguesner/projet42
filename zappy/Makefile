# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/02 08:16:06 by nguezell          #+#    #+#              #
#    Updated: 2014/06/26 17:44:31 by nguezell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNITY = /Applications/Unity/Unity.app/Contents/MacOS/Unity

JAVA_PATH = client_src
GFX_PATH = gfx_src
SERVER_PATH = serveur_src

SERVEUR = serveur

AT = gfx.app

CLIENT = $(JAVA_PATH)/Client.java\
	$(JAVA_PATH)/Drone.java\
	$(JAVA_PATH)/Opt.java \
	$(JAVA_PATH)/Action.java \
	$(JAVA_PATH)/Inventaire.java \
	$(JAVA_PATH)/Lvl.java
JC = javac
.SUFFIXES: .java .class
.java.class:
		$(JC) $(CLIENT)

GFX = gfx
SRC = $(SERVER_PATH)/main.c \
	$(SERVER_PATH)/initenv.c \
	$(SERVER_PATH)/ft_perror.c \
	$(SERVER_PATH)/ft_error.c \
	$(SERVER_PATH)/ft_accept.c \
	$(SERVER_PATH)/cleanclient.c \
	$(SERVER_PATH)/ft_read.c \
	$(SERVER_PATH)/ft_write.c \
	$(SERVER_PATH)/loop.c \
	$(SERVER_PATH)/initclients.c \
	$(SERVER_PATH)/genere_case.c \
	$(SERVER_PATH)/ft_select.c \
	$(SERVER_PATH)/checkclients.c \
	$(SERVER_PATH)/ft_cmd.c \
	$(SERVER_PATH)/ft_connect.c \
	$(SERVER_PATH)/eat.c \
	$(SERVER_PATH)/microtime.c \
	$(SERVER_PATH)/preprend.c \
	$(SERVER_PATH)/prend.c \
	$(SERVER_PATH)/preavance.c \
	$(SERVER_PATH)/avance.c \
	$(SERVER_PATH)/predroite.c \
	$(SERVER_PATH)/droite.c \
	$(SERVER_PATH)/pregauche.c \
	$(SERVER_PATH)/gauche.c \
	$(SERVER_PATH)/prepose.c \
	$(SERVER_PATH)/pose.c \
	$(SERVER_PATH)/prevoir.c \
	$(SERVER_PATH)/voir.c \
	$(SERVER_PATH)/inside.c \
	$(SERVER_PATH)/modulo.c \
	$(SERVER_PATH)/preinventaire.c \
	$(SERVER_PATH)/inventaire.c \
	$(SERVER_PATH)/opt.c \
	$(SERVER_PATH)/new_name.c \
	$(SERVER_PATH)/ft_initgraph.c \
	$(SERVER_PATH)/connect_nbr.c \
	$(SERVER_PATH)/connect_gfx.c \
	$(SERVER_PATH)/maj_gfx.c \
	$(SERVER_PATH)/move_gfx.c \
	$(SERVER_PATH)/prebroadcast.c \
	$(SERVER_PATH)/broadcast.c \
	$(SERVER_PATH)/broadcast_gfx.c \
	$(SERVER_PATH)/prefork.c \
	$(SERVER_PATH)/pond.c \
	$(SERVER_PATH)/create_oeuf.c \
	$(SERVER_PATH)/checkoeuf.c \
	$(SERVER_PATH)/isoeuf.c \
	$(SERVER_PATH)/destroy_oeuf.c \
	$(SERVER_PATH)/pond_gfx.c \
	$(SERVER_PATH)/contenue.c \
	$(SERVER_PATH)/preexpulse.c \
	$(SERVER_PATH)/expulse.c \
	$(SERVER_PATH)/ex_dir.c \
	$(SERVER_PATH)/preincantation.c \
	$(SERVER_PATH)/incantation.c \
	$(SERVER_PATH)/explode_player.c \
	$(SERVER_PATH)/aff_map.c \
	$(SERVER_PATH)/explode_case.c \
	$(SERVER_PATH)/lvl_un.c \
	$(SERVER_PATH)/lvl_deux.c \
	$(SERVER_PATH)/lvl_trois.c \
	$(SERVER_PATH)/lvl_quatre.c \
	$(SERVER_PATH)/lvl_cinq.c \
	$(SERVER_PATH)/lvl_six.c \
	$(SERVER_PATH)/lvl_sept.c \
	$(SERVER_PATH)/end_game.c \
	$(SERVER_PATH)/next_action.c
CLASS = $(CLIENT:.java=.class)
OBJ = $(SRC:.c=.o)
CC = gcc -Wall -Wextra -Werror -O2 -I $(SERVER_PATH) -I $(SERVER_PATH)/libft

all: LIB serveur client gfx

gfx: gfx_bin
		 @if test ! -d "gfx.app"; then $(UNITY) -batchmode -nographics -nolog -projectPath $(PWD)/$(GFX_PATH) -buildOSX64Player $(PWD)/gfx.app -quit || echo "Activate unity licence or close unity please"; fi
gfx_bin:
	@touch gfx
	@echo "#!/bin/bash \nopen gfx.app;" > gfx
	@chmod +x gfx

client: $(CLASS)
	@cp  $(JAVA_PATH)/client .
	@chmod +x client

$(JAVA_CMP):
	javac $(JAVA_SRC)
serveur: $(OBJ)
	$(CC) $(OBJ) $(SERVER_PATH)/libft/libft.a -o $(SERVEUR)
LIB:
	make -C $(SERVER_PATH)/libft

clean:
	rm -rf $(CLASS) $(OBJ)
fclean: clean
	rm -rf $(SERVEUR) client $(GFX) gfx.app
re: fclean all
